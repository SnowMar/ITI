<?php
// Include database class
include_once 'config/Database.php';

// Get database connection
$database = new Database();
$conn = $database->getConnection();

// SQL to create table
$sql = "CREATE TABLE IF NOT EXISTS users (
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL,
    room VARCHAR(50) NOT NULL,
    profile VARCHAR(255) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;";

try {
    // Execute query
    $conn->exec($sql);
    echo "Database setup completed successfully.";
    echo "<br><a href='index.php'>Go to Home</a>";
} catch(PDOException $e) {
    echo "Error creating table: " . $e->getMessage();
}