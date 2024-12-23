import java.sql.SQLException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class DatabaseConnection {

    Connection connect = null;
    Statement statement = null;
    ResultSet resultSet = null;

    public void connectToDatabase() {
        try {
            // Database connection
            connect = DriverManager.getConnection("jdbc:mysql://localhost:3306/iti", "root", "");
            statement = connect.createStatement();
            resultSet = statement.executeQuery("SELECT * FROM students");
            
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            // Close resources
            try {
                if (resultSet != null) resultSet.close();
                if (statement != null) statement.close();
                if (connect != null) connect.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
    public static void main(String[] args) {
        DatabaseConnection db = new DatabaseConnection();
        db.connectToDatabase();
    }
}