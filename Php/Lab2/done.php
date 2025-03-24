<?php
session_start();

define("FILE_NAME", "customer.txt");

function validateInput($data) {
    return htmlspecialchars(trim($data));
}

function isValidEmail($email) {
    return filter_var($email, FILTER_VALIDATE_EMAIL);
}

$firstName = '';
$lastName = '';
$email = '';
$gender = '';
$invalidFields = [];

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $errors = [];

    $firstName = validateInput($_POST['first_name'] ?? '');
    $lastName = validateInput($_POST['last_name'] ?? '');
    $email = validateInput($_POST['email'] ?? '');
    $gender = validateInput($_POST['gender'] ?? '');
    
    if (empty($firstName)) {
        $errors[] = "First name is required.";
        $invalidFields[] = 'first_name';
    }
    
    if (empty($lastName)) {
        $errors[] = "Last name is required.";
        $invalidFields[] = 'last_name';
    }
    
    if (empty($email)) {
        $errors[] = "Email is required.";
        $invalidFields[] = 'email';
    } elseif (!isValidEmail($email)) {
        $errors[] = "Valid email is required.";
        $invalidFields[] = 'email';
    }
    
    if (empty($gender)) {
        $errors[] = "Gender is required.";
        $invalidFields[] = 'gender';
    }

    $captchaInput = $_POST['captcha'] ?? '';
    if (!isset($_SESSION['captcha']) || $captchaInput !== $_SESSION['captcha']) {
        $errors[] = "Incorrect CAPTCHA!";
        $invalidFields[] = 'captcha';
    }

    if (empty($errors)) {
        $record = "$firstName|$lastName|$email|$gender\n";
        file_put_contents(FILE_NAME, $record, FILE_APPEND);
        unset($_SESSION['captcha']);
        header("Location: done.php");
        exit();
    } else {
        $queryParams = http_build_query([
            'first_name' => $firstName,
            'last_name' => $lastName,
            'email' => $email,
            'gender' => $gender,
            'errors' => json_encode($errors),
            'invalid_fields' => json_encode($invalidFields)
        ]);
        header("Location: form.html?" . $queryParams);
        exit();
    }
}

$customers = file_exists(FILE_NAME) ? file(FILE_NAME, FILE_IGNORE_NEW_LINES) : [];
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration Success</title>
    <style>
        body { font-family: Arial, sans-serif; padding: 20px; }
        .success-message { 
            background-color: #e8f5e9; 
            padding: 20px; 
            border-radius: 8px; 
            margin-bottom: 20px;
            border-left: 5px solid #4caf50;
        }
        .button-container {
            display: flex;
            gap: 10px;
            margin: 20px 0;
        }
        .btn {
            padding: 10px 15px;
            border: none;
            border-radius: 5px;
            text-decoration: none;
            color: white;
            font-weight: bold;
            cursor: pointer;
        }
        .btn-primary {
            background-color: #6a11cb;
        }
        .btn-secondary {
            background-color: #2575fc;
        }
        .btn:hover {
            opacity: 0.9;
        }
    </style>
</head>
<body>
    <div class="success-message">
        <h2>Registration Successful!</h2>
        <p>Your information has been successfully saved.</p>
    </div>

    <div class="button-container">
        <a href="form.html" class="btn btn-primary">Add Another Customer</a>
        <a href="allCustomers.php" class="btn btn-secondary">View All Customers</a>
    </div>
</body>
</html>
