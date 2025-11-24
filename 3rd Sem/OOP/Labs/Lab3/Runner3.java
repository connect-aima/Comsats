public class Runner3 {
    public static void main(String[] args) {
       
        int[] marks1 = {80, 75, 90, 85, 95};
        int[] marks2 = {60, 70, 65, 75, 80};

       
        Students s1 = new Students("Ali", marks1);
        Students s2 = new Students("Sara", marks2);

       
        double avg1 = s1.average();
        double avg2 = s2.average();

       
        System.out.println(s1.getName() + "'s average: " + avg1);
        System.out.println(s2.getName() + "'s average: " + avg2);

        
        if (avg1 > avg2) {
            System.out.println(s1.getName() + " has higher average.");
        } else if (avg2 > avg1) {
            System.out.println(s2.getName() + " has higher average.");
        } else {
            System.out.println("Both have equal average.");
        }

        
        Students s3 = new Students(s1.getName(), marks2);
        System.out.println("Third student " + s3.getName() +
                           " has average: " + s3.average());
    }


}
