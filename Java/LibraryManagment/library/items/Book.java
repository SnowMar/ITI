package library.items;

public class Book extends LibraryItem {
    private String author;

    public Book(String title, String itemId, String author) {
        super(title, itemId);
        this.author = author;
    }

    public String getAuthor() {
        return author;
    }

    @Override
    public String getType() {
        return "Book";
    }

    @Override
    public String toString() {
        return super.toString() + ", Author: " + author;
    }
}
