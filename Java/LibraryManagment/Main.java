import library.Book;

public class Main {
    public static void main(String[] args) {
        Library library = new Library();
        library.addLibraryItem(new Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
        library.addLibraryItem(new Book("To Kill a Mockingbird", "Harper Lee", 1960));
        library.addLibraryItem(new Book("1984", "George Orwell", 1949));
        library.addLibraryItem(new Book("Pride and Prejudice", "Jane Austen", 1813));
        library.addLibraryItem(new Book("The Catcher in the Rye", "J.D. Salinger", 1951));
        library.addLibraryItem(new Book("The Hobbit", "J.R.R. Tolkien", 1937));
        library.addLibraryItem(new Book("The Lord of the Rings", "J.R.R. Tolkien", 1954));
        library.addLibraryItem(new Book("Animal Farm", "George Orwell", 1945));
        library.addLibraryItem(new Book("Brave New World", "Aldous Huxley", 1932));
        library.addLibraryItem(new Book("The Grapes of Wrath", "John Steinbeck", 1939));
        library.addLibraryItem(new Book