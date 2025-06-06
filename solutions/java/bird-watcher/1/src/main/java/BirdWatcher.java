
class BirdWatcher {
    private final int[] birdsPerDay;

    public BirdWatcher(int[] birdsPerDay) {
        this.birdsPerDay = birdsPerDay.clone();
    }

    public int[] getLastWeek() {
        return this.birdsPerDay;
    }

    public int getToday() {
        return this.birdsPerDay.length > 0 ? this.birdsPerDay[this.birdsPerDay.length -1] : 0;
    }

    public void incrementTodaysCount() {
        this.birdsPerDay[this.birdsPerDay.length -1]++;
    }

    public boolean hasDayWithoutBirds() {
        for (var count: this.birdsPerDay){
            if (count == 0) return true;
        }
        
        return false;
    }

    public int getCountForFirstDays(int numberOfDays) {
        int countForFirstDays = 0;
        
        for (int i = 0; i < (numberOfDays > 7 ? 7 : numberOfDays); i++){
            countForFirstDays += this.birdsPerDay[i];
        }

        return countForFirstDays;
    }

    public int getBusyDays() {
        int busyDays = 0;
        
        for (var count: this.birdsPerDay){
            if (count >= 5 ) busyDays++;
        }

        return busyDays;
    }
}
