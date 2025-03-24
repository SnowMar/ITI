<?php
session_start();

include_once '../config/Database.php';
include_once '../models/User.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $email = trim($_POST['email'] ?? '');
    $password = $_POST['password'] ?? '';
    
    if (empty($email) || empty($password)) {
        header("Location: ../auth/login.php?error=Email and password are required");
        exit;
    }
    
    $database = new Database();
    $db = $database->getConnection();
    
    $user = new User($db);
    
    if($user->authenticate($email, $password)) {
        $_SESSION['user'] = [
            'id' => $user->id,
            'username' => $user->username,
            'email' => $email,
            'room' => $user->room,
            'profile' => $user->profile
        ];
        
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
