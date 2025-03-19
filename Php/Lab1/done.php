<?php

session_start();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $fname = htmlspecialchars($_POST['fname']);
    $lname = htmlspecialchars($_POST['lname']);
    $address = htmlspecialchars($_POST['address']);
    $country = htmlspecialchars($_POST['country']);
    $gender = isset($_POST['gender']) ? $_POST['gender'] : "";
    $skills = isset($_POST['skills']) ? implode(", ", $_POST['skills']) : "None";
    $username = htmlspecialchars($_POST['username']);
    $department = htmlspecialchars($_POST['department']);
    $captcha = $_POST['captcha'];

    if(!isset($_SESSION['captcha']) || $captcha !== $_SESSION['captcha']){
        die("Invalid Captcha!");
    }

    echo "<h2>Review</h2>";
    echo "<p>Thanks ($gender) $fname $lname</p>";
    echo "<h3>Please Review Your Information</h3>";
    echo "<p>Name: $fname $lname</p>";
    echo "<p>Address: $address</p>";
    echo "<p>Country: $country</p>";
    echo "<p>Your Skills: $skills</p>";
    echo "<p>Username: $username</p>";
    echo "<p>Department: $department</p>";
    unset($_SESSION['captcha']);

} else {
    die("⚠ Invalid request. Please submit the form properly. <a href='index.html'>Go back</a>");
}
?>
