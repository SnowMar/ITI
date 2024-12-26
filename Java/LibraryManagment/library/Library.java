package library;

import library.items.LibraryItem;
import library.exceptions.libExceptions;
import java.util.ArrayList;
import java.util.List;

public class Library {
    private List<LibraryItem> items;

    public Library() {
        this.items = new ArrayList<>();
    }

    public void addItem(LibraryItem item) {
        items.add(item);
    }

    public LibraryItem findItemById(String id) throws libExceptions {
        for (LibraryItem item : items) {
            if (item.getItemId().equals(id)) {
                return item;
            }
        }
        throw new libExceptions("Item with ID " + id + " not found.");
    }

    public List<LibraryItem> getAllItems() {
        return items;
    }
}
