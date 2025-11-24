
import java.util.ArrayList;
import java.util.Random;

 class RandomBox<T> {

    private ArrayList<T> items = new ArrayList<>();
    private Random rand = new Random();

    // Add an item to the box
    public void add(T item) {
        items.add(item);
    }

    // Check if the box is empty
    public boolean isEmpty() {
        return items.isEmpty();
    }

    // Draw a random item from the box
    public T drawItem() {
        if (isEmpty()) {
            return null;    // return null if empty
        }
        int index = rand.nextInt(items.size());
        return items.get(index);
    }
}
public class TestRandomBox {

    public static void main(String[] args) {

        // Create a box of Strings (names)
        RandomBox<String> nameBox = new RandomBox<>();
        nameBox.add("Aima");
        nameBox.add("Ali");
        nameBox.add("Sara");
        nameBox.add("Hamza");

        System.out.println("Random name: " + nameBox.drawItem());
        System.out.println("Random name: " + nameBox.drawItem());

        // Create a box of Integers (lottery numbers)
        RandomBox<Integer> lotteryBox = new RandomBox<>();
        lotteryBox.add(5);
        lotteryBox.add(17);
        lotteryBox.add(23);
        lotteryBox.add(42);

        System.out.println("Random lottery number: " + lotteryBox.drawItem());

        // Test empty box
        RandomBox<Double> emptyBox = new RandomBox<>();
        System.out.println("Draw from empty box: " + emptyBox.drawItem()); // should print null
    }
}
