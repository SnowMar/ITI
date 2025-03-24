<?php
session_start();

if (!isset($_SESSION['user'])) {
    header("Location: ../auth/login.php");
    exit;
}

include_once '../config/Database.php';
include_once '../models/User.php';

$database = new Database();
$db = $database->getConnection();

$user = new User($db);

if (isset($_GET['delete'])) {
    $id = intval($_GET['delete']);
    if ($user->delete($id)) {
        header("Location: allCustomers.php?success=Record deleted successfully");
    } else {
        header("Location: allCustomers.php?error=Failed to delete record");
    }
    exit;
}

$stmt = $user->getAll();
$customers = $stmt->fetchAll(PDO::FETCH_ASSOC);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>All Customer Records</title>
    <link rel="stylesheet" href="../styles/Cstyles.css">
</head>
<body>

<h2>All Customer Records</h2>

<?php if (isset($_GET['success'])): ?>
    <div class="success-message">
        <?= htmlspecialchars($_GET['success']) ?>
    </div>
<?php endif; ?>

<?php if (isset($_GET['error'])): ?>
    <div class="error-message">
        <?= htmlspecialchars($_GET['error']) ?>
    </div>
<?php endif; ?>

<?php if (!empty($customers)): ?>
    <div class="count-info">
        Total Records: <?= count($customers) ?>
    </div>
    
    <table>
        <tr>
            <th>#</th>
            <th>Username</th>
            <th>Email</th>
            <th>Room</th>
            <th>Action</th>
        </tr>
        <?php foreach ($customers as $index => $customer): ?>
            <tr>
                <td><?= $index + 1 ?></td>
                <td><?= htmlspecialchars($customer['username'] ?? '') ?></td>
                <td><?= htmlspecialchars($customer['email'] ?? '') ?></td>
                <td><?= htmlspecialchars($customer['room'] ?? '') ?></td>
                <td><a href="?delete=<?= $customer['id'] ?>" class="delete-btn" onclick="return confirm('Are you sure you want to delete this record?')">Delete</a></td>
            </tr>
        <?php endforeach; ?>
    </table>
<?php else: ?>
    <div class="no-records">
        <p>No customer records found.</p>
    </div>
<?php endif; ?>

<div class="button-container">
    <a href="../welcome.php" class="btn btn-primary">Back to Dashboard</a>
    <a href="../index.php" class="btn btn-secondary">Add New Customer</a>
    <a href="../auth/logout.php" class="btn btn-info">Logout</a>
</div>

</body>
</html>