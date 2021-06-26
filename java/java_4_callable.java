public class myCallAble implements Callable<int> {
    private Intiger baseNumber;

    public myCallAble(Integer baseNumber) {
        this.baseNumber = baseNumber;
    }

    public static Integer squareNumber(Integer toDouble) {
        return toDouble * 2;
    }

    public Integer call() {
        return this.squareNumber(baseNumber);
    }
}