<?php
define("FILE_NAME", "customer.txt");

function deleteRecord($index) {
    $records = file(FILE_NAME, FILE_IGNORE_NEW_LINES);
    if (isset($records[$index])) {
        unset($records[$index]);
        file_put_contents(FILE_NAME, implode("\n", $records) . "\n");
    }
}

if (isset($_GET['delete'])) {
    deleteRecord($_GET['delete']);
    header("Location: allCustomers.php");
    exit();
}

$customers = file_exists(FILE_NAME) ? file(FILE_NAME, FILE_IGNORE_NEW_LINES) : [];
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>All Customer Records</title>
    <link rel="stylesheet" href="Cstyles.css">
</head>
<body>

<h2>All Customer Records</h2>

<?php if (!empty($customers)): ?>
    <div class="count-info">
        Total Records: <?= count($customers) ?>
    </div>
    
    <table>
        <tr>
            <th>#</th>
            <th>First Name</th>
            <th>Last Name</th>
            <th>Email</th>
            <th>Gender</th>
            <th>Action</th>
        </tr>
        <?php foreach ($customers as $index => $customer): 
            $data = explode("|", $customer); ?>
            <tr>
                <td><?= $index + 1 ?></td>
                <td><?= htmlspecialchars($data[0] ?? '') ?></td>
                <td><?= htmlspecialchars($data[1] ?? '') ?></td>
                <td><?= htmlspecialchars($data[2] ?? '') ?></td>
                <td><?= htmlspecialchars($data[3] ?? '') ?></td>
                <td><a href="?delete=<?= $index ?>" class="delete-btn" onclick="return confirm('Are you sure you want to delete this record?')">Delete</a></td>
            </tr>
        <?php endforeach; ?>
    </table>
<?php else: ?>
    <div class="no-records">
        <p>No customer records found.</p>
    </div>
<?php endif; ?>

<div class="button-container">
    <a href="form.html" class="btn btn-primary">Add New Customer</a>
</div>

</body>
</html>
