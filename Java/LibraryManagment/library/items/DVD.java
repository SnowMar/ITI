package library.items;

public class DVD extends LibraryItem{
    private String dvdType;
    
    public DVD(String title, String itemId, String dvdType){
        super(title, itemId);
        this.dvdType = dvdType;
    }

    public String getdvdType(){
        return dvdType;
    }

    @Override
    public String getType(){
        return "DVD";
    }

    @Override
    public String toString(){
        return super.toString() + ", DVD Type: " + dvdType;
    }
}
