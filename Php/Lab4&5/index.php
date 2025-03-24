<?php
session_start();
if (isset($_SESSION['user'])) {
    header("Location: welcome.php");
    exit;
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add User</title>
    <link rel="stylesheet" href="styles/styles.css">
</head>
<body>
    <div class="container">
        <h2>Add User</h2>
        
        <?php
        
        if (isset($_GET['error'])) {
            echo '<div class="error-message">';
            $errors = explode(',', $_GET['error']);
            foreach ($errors as $error) {
                echo '<p>' . htmlspecialchars($error) . '</p>';
            }
            echo '</div>';
        }
        
        $username = isset($_GET['username']) ? htmlspecialchars($_GET['username']) : '';
        $email = isset($_GET['email']) ? htmlspecialchars($_GET['email']) : '';
        ?>
        
        <form action="validation/process.php" method="post" enctype="multipart/form-data">
            <div class="form-group">
                <label for="username">Username</label>
                <input type="text" id="username" name="username" value="<?php echo $username; ?>">
            </div>
            
            <div class="form-group">
                <label for="email">Email</label>
                <input type="text" id="email" name="email" value="<?php echo $email; ?>">
            </div>
            
            <div class="form-group">
                <label for="password">Password</label>
                <input type="password" id="password" name="password">
                <p class="hint">Password must be 6 characters, no special characters except underscore, no capital letters</p>
            </div>
            
            <div class="form-group">
                <label for="confirm_password">Confirm Password</label>
                <input type="password" id="confirm_password" name="confirm_password">
            </div>
            
            <div class="form-group">
                <label for="room_no">Room No</label>
                <select id="room_no" name="room_no">
                    <option value="">Select a room</option>
                    <option value="Open Source">Open Source</option>
                    <option value="DataBase">DataBase</option>
                    <option value="Cloud">Cloud</option>
                </select>
            </div>
            
            <div class="form-group">
                <label for="profile_picture">Profile Picture</label>
                <input type="file" id="profile_picture" name="profile_picture">
            </div>
            
            <div class="form-buttons">
                <button type="submit">Submit</button>
                <button type="reset">Reset</button>
            </div>
        </form>
        
        <div class="login-link">
            <p>Already have an account? <a href="auth/login.php">Login here</a></p>
        </div>
    </div>
</body>
</html>