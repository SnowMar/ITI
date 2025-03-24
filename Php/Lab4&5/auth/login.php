<?php
session_start();

if (isset($_SESSION['user'])) {
    header("Location: ../welcome.php");
    exit;
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cafeteria - Login</title>
    <link rel="stylesheet" href="../styles/styles.css">
</head>
<body>
    <div class="container login-container">
        <h2>Cafeteria</h2>
        
        <?php
        if (isset($_GET['registered']) && $_GET['registered'] == 1) {
            echo '<div class="success-message">Registration successful! Please login.</div>';
        }
        
        if (isset($_GET['error'])) {
            echo '<div class="error-message">' . htmlspecialchars($_GET['error']) . '</div>';
        }
        ?>
        
        <form action="../validation/verify.php" method="post">
            <div class="form-group">
                <label for="email">Email</label>
                <input type="text" id="email" name="email">
            </div>
            
            <div class="form-group">
                <label for="password">Password</label>
                <input type="password" id="password" name="password">
            </div>
            
            <div class="form-buttons">
                <button type="submit">Login</button>
            </div>
            <div class="form-buttons">
                <a href="../index.php">Register</a>
            </div>
        </form>
    </div>
</body>
</html>