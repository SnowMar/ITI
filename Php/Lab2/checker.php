<?php
session_start();

$captchaCode = substr(str_shuffle("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"), 0, 6);
$_SESSION['captcha'] = $captchaCode;

header('Content-Type: application/image');

$image = imageCreate(100, 30);
$bgColor = imagecolorallocate($image, 255, 255, 255);
$textColor = imagecolorallocate($image, 0, 0, 0);

imagestring($image, 5, 15, 5, $captchaCode, $textColor);
imagepng($image);
imagedestroy($image);
?>
