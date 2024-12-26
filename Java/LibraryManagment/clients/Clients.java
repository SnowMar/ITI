package clients;

public class Clients {
    private String name;
    private String clientId;

    public Clients(String name, String clientId) {
        this.name = name;
        this.clientId = clientId;
    }

    public String getName() {
        return name;
    }

    public String getClientId() {
        return clientId;
    }

    @Override
    public String toString() {
        return "Client Name: " + name + ", Client ID: " + clientId;
    }
}
