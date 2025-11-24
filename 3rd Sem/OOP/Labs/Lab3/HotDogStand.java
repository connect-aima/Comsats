public class HotDogStand {
    private int id;
    private int hotDogsSold;

    public HotDogStand(int id, int hotDogsSold) {
        this.id = id;
        this.hotDogsSold = hotDogsSold;
    }

    public void justSold() {
        hotDogsSold++;
    }

    public int getHotDogsSold() {
        return hotDogsSold;
    }

    public int getId() {
        return id;
    }
}
