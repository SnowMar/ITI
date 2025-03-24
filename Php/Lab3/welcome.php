<?php
session_start();

if (!isset($_SESSION['user'])) {
    header("Location: auth/login.php");
    exit;
}

$user = $_SESSION['user'];
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Welcome</title>
    <link rel="stylesheet" href="styles/styles.css">
</head>
<body>
    <div class="container welcome-container">
        <h2>Welcome, <?php echo htmlspecialchars($user['username']); ?>!</h2>
        
        <div class="user-profile">
            <div class="profile-image">
                <img src="<?php echo 'assets/images/' . htmlspecialchars($user['profile']); ?>" alt="Profile Picture">
            </div>
            
            <div class="user-details">
                <p><strong>Username:</strong> <?php echo htmlspecialchars($user['username']); ?></p>
                <p><strong>Email:</strong> <?php echo htmlspecialchars($user['email']); ?></p>
                <p><strong>Room:</strong> <?php echo htmlspecialchars($user['room']); ?></p>
                <a href="routes/allCustomers.php" class="update-btn">All Customers</a>
            </div>
        </div>
        
        <div class="logout-section">
            <a href="auth/logout.php" class="logout-btn">Logout</a>
        </div>
    </div>
</body>
</html>