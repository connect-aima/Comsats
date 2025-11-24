class Distance {
    int feet;
    int inches;

    Distance() {
        this.feet = 4;
        this.inches = 5;
    }

    Distance(int feet, int inches) {
        setDistance(feet, inches);
    }

    void setDistance(int feet, int inches) {
        if (feet >= 0 && inches >= 0)
            this.feet = feet;
            this.inches = inches;
    }

    void getDistance() {
        System.out.println("Distance is " + feet + "feet and " + inches + "inches.");
    }

    Distance addDistance(Distance d2) {
        int newFeet = this.feet + d2.feet;
        int newInches = this.inches + d2.inches;

        if (newInches >= 12) {
            newFeet += newInches / 12;
            newInches = newInches % 12;
        }

        return new Distance(newFeet, newInches);
    }
}
