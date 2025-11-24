public class Runner {
    public static void main(String[] args) {
        Distance d1 = new Distance(3, 4);
        d1.getDistance();
        Distance d2 = new Distance(6, 7);
        d2.getDistance();
        Distance d3 = d1.addDistance(d2);
        d3.getDistance();

    }
}
