import clients.Clients;
import library.Library;
import library.items.*;
import library.exceptions.libExceptions;

public class Main {
    public static void main(String[] args) {
        Library library = new Library();
        Clients client = new Clients("Alice", "C123");

        library.addItem(new Book("The Great Gatsby", "B001", "F. Scott Fitzgerald"));
        library.addItem(new Magazine("Time Magazine", "M001", 42));

        System.out.println("Library Items:");
        for (LibraryItem item : library.getAllItems()) {
            System.out.println(item);
        }

        try {
            System.out.println("\nSearching for item with ID 'B001':");
            System.out.println(library.findItemById("B001"));
        } catch (libExceptions e) {
            System.err.println(e.getMessage());
        }

        System.out.println("\nClient Details:");
        System.out.println(client);
    }
}
