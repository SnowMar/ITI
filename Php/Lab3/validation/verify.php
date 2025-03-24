<?php
session_start();
define("USERS_FILE", "../data/users.txt");

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $email = trim($_POST['email'] ?? '');
    $password = $_POST['password'] ?? '';
    
    if (empty($email) || empty($password)) {
        header("Location: ../auth/login.php?error=Email and password are required");
        exit;
    }
    
    if (!file_exists(USERS_FILE)) {
        header("Location: ../auth/login.php?error=No users found");
        exit;
    }
    
    $users = file(USERS_FILE, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
    $authenticated = false;
    
    foreach ($users as $user) {
        $user_data = explode('|', $user);
        
        if (count($user_data) < 5) continue;
        
        $stored_username = $user_data[0];
        $stored_email = $user_data[1];
        $stored_password = $user_data[2];
        $stored_room = $user_data[3];
        $stored_profile = $user_data[4];
        
        if ($stored_email === $email && $stored_password === $password) {
            $_SESSION['user'] = [
                'username' => $stored_username,
                'email' => $stored_email,
                'room' => $stored_room,
                'profile' => $stored_profile
            ];
            
            $authenticated = true;
            break;
        }
    }
    
    if ($authenticated) {
        header("Location: ../welcome.php");
        exit;
    } else {
        header("Location: ../auth/login.php?error=Invalid email or password");
        exit;
    }
} else {
    header("Location: ../auth/login.php");
    exit;
}