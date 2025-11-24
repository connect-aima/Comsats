public class Students {
   
   
    private String name;
    private int[] resultArray; 

   
    public Students(String name, int[] resultArray) {
        this.name = name; 
        this.resultArray = new int[resultArray.length];
        for (int i = 0; i < resultArray.length; i++) {
            this.resultArray[i] = resultArray[i];
        }
    }

   
    public double average() {
        int sum = 0;
        for (int mark : resultArray) {
            sum += mark;
        }
        return (double) sum / resultArray.length;
    }

    
    public String getName() {
        return name;
    }
}


