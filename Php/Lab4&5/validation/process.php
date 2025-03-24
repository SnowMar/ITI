<?php
include_once '../config/Database.php';
include_once '../models/User.php';

define("UPLOAD_DIR", "../assets/images/");

if (!is_dir(UPLOAD_DIR)) {
    mkdir(UPLOAD_DIR, 0755, true);
}

$errors = [];

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = trim($_POST['username'] ?? '');
    $email = trim($_POST['email'] ?? '');
    $password = $_POST['password'] ?? '';
    $confirm_password = $_POST['confirm_password'] ?? '';
    $room_no = $_POST['room_no'] ?? '';
    
    if (empty($username)) {
        $errors[] = "Username is required";
    }
    
    if (empty($email)) {
        $errors[] = "Email is required";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $errors[] = "Invalid email format";
    }
    
    if (empty($password)) {
        $errors[] = "Password is required";
    } elseif (strlen($password) < 6) {
        $errors[] = "Password must be at least 6 characters";
    } elseif (!preg_match('/^(?=.*[A-Z])(?=.*[a-z])(?=.*\d).+$/', $password)) {
        $errors[] = "Password must contain at least one uppercase letter, one lowercase letter, and one number";
    }
    
    if ($password !== $confirm_password) {
        $errors[] = "Passwords do not match";
    }
    
    if (empty($room_no)) {
        $errors[] = "Room number is required";
    }
    
    $profile_picture = '';
    if (isset($_FILES['profile_picture']) && $_FILES['profile_picture']['error'] == 0) {
        $allowed_types = ['image/jpeg', 'image/png', 'image/gif'];
        $file_info = finfo_open(FILEINFO_MIME_TYPE);
        $file_type = finfo_file($file_info, $_FILES['profile_picture']['tmp_name']);
        finfo_close($file_info);
        
        if (!in_array($file_type, $allowed_types)) {
            $errors[] = "Only JPG, PNG, and GIF images are allowed";
        } else {
            $file_extension = pathinfo($_FILES['profile_picture']['name'], PATHINFO_EXTENSION);
            $profile_picture = $username . "_" . time() . "." . $file_extension;
            
            if (!move_uploaded_file($_FILES['profile_picture']['tmp_name'], UPLOAD_DIR . $profile_picture)) {
                $errors[] = "Failed to upload profile picture";
            }
        }
    } else {
        $errors[] = "Profile picture is required";
    }
    
    if (empty($errors)) {
        $database = new Database();
        $db = $database->getConnection();
        
        $user = new User($db);
        
        $user->email = $email;
        if($user->emailExists()) {
            $errors[] = "Email already exists";
        } else {
            $user->username = $username;
            $user->email = $email;
            $user->password = $password;
            $user->room = $room_no;
            $user->profile = $profile_picture;
            
            if($user->create()) {
                header("Location: ../auth/login.php?registered=1");
                exit;
            } else {
                $errors[] = "Failed to create user";
            }
        }
    }
    
    if (!empty($errors)) {
        $error_string = implode(',', $errors);
        header("Location: ../index.php?error=" . urlencode($error_string) . 
               "&username=" . urlencode($username) . 
               "&email=" . urlencode($email));
        exit;
    }
} else {
    header("Location: ../index.php");
    exit;
}