<?php
class User {

    private $conn;
    private $table_name = "users";
    public $id;
    public $username;
    public $email;
    public $password;
    public $room;
    public $profile;
    
    /**
     * Constructor with $db as database connection
     * @param PDO $db
     */
    public function __construct($db) {
        $this->conn = $db;
    }
    
    /**
     * Create user
     * @return boolean
     */
    public function create() {
        $query = "INSERT INTO " . $this->table_name . " 
                SET username=:username, email=:email, password=:password, 
                    room=:room, profile=:profile";
        
        $stmt = $this->conn->prepare($query);
        
        $this->username = htmlspecialchars(strip_tags($this->username));
        $this->email = htmlspecialchars(strip_tags($this->email));
        $this->room = htmlspecialchars(strip_tags($this->room));
        $this->profile = htmlspecialchars(strip_tags($this->profile));
        
        $this->password = password_hash($this->password, PASSWORD_DEFAULT);
        
        $stmt->bindParam(":username", $this->username);
        $stmt->bindParam(":email", $this->email);
        $stmt->bindParam(":password", $this->password);
        $stmt->bindParam(":room", $this->room);
        $stmt->bindParam(":profile", $this->profile);
        
        if($stmt->execute()) {
            return true;
        }
        
        return false;
    }
    
    /**
     * Check if email already exists
     * @return boolean
     */
    public function emailExists() {
        $query = "SELECT id, username, password, room, profile 
                FROM " . $this->table_name . " 
                WHERE email = ?
                LIMIT 0,1";
        
        $stmt = $this->conn->prepare($query);
        
        $stmt->bindParam(1, $this->email);
        
        $stmt->execute();
        
        $num = $stmt->rowCount();
        
        // If email exists, assign values to object properties for easy access
        if($num > 0) {
            $row = $stmt->fetch(PDO::FETCH_ASSOC);
            
            $this->id = $row['id'];
            $this->username = $row['username'];
            $this->password = $row['password'];
            $this->room = $row['room'];
            $this->profile = $row['profile'];
            
            return true;
        }
        
        return false;
    }
    
    /**
     * Authenticate user
     * @param string $email
     * @param string $password
     * @return boolean
     */
    public function authenticate($email, $password) {
        $this->email = $email;
        
        if($this->emailExists()) {
            if(password_verify($password, $this->password)) {
                return true;
            }
        }
        
        return false;
    }
    
    /**
     * Get all users
     * @return PDOStatement
     */
    public function getAll() {
        $query = "SELECT * FROM " . $this->table_name . " ORDER BY id DESC";
        
        $stmt = $this->conn->prepare($query);
        
        $stmt->execute();
        
        return $stmt;
    }
    
    /**
     * Delete a user record
     * @param int $id
     * @return boolean
     */
    public function delete($id) {
        $query = "DELETE FROM " . $this->table_name . " WHERE id = ?";
        
        $stmt = $this->conn->prepare($query);
        
        $id = htmlspecialchars(strip_tags($id));
        
        $stmt->bindParam(1, $id);
        
        if($stmt->execute()) {
            return true;
        }
        
        return false;
    }
}
