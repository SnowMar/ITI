package library.items;

public class Magazine extends LibraryItem {
    private int issueNumber;

    public Magazine(String title, String itemId, int issueNumber) {
        super(title, itemId);
        this.issueNumber = issueNumber;
    }

    public int getIssueNumber() {
        return issueNumber;
    }

    @Override
    public String getType() {
        return "Magazine";
    }

    @Override
    public String toString() {
        return super.toString() + ", Issue Number: " + issueNumber;
    }
}
