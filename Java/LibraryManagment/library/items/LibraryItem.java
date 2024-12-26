package library.items;

public abstract class LibraryItem {
    private String title;
    private String itemId;

    public LibraryItem(String title, String itemId) {
        this.title = title;
        this.itemId = itemId;
    }

    public String getTitle() {
        return title;
    }

    public String getItemId() {
        return itemId;
    }

    public abstract String getType();

    @Override
    public String toString() {
        return "Title: " + title + ", ID: " + itemId + ", Type: " + getType();
    }
}
