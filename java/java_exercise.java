import java.util.concurent.*;

public static int tab[2][2] = {{1,2}, {10,12}};

public static class Counter implementes Callable<String> {
    int sum = 0;

    public Counter() {
    }

    public int calcRow(int row_idx) {
        int tmp = 0;

        for (int i=0; i<tab.length[row_idx].length; i++) {
            tmp += tab[row_idx][i];
        }
        
        return tmp;
    }

    public void synchronized increment(int sync_by) {
        sum += sync_by;
    }

    public static String call() {
        return "Sum: " + sum;
    } 
}

int main(String[] args) {
    inr AMOUNT_THRDS = 10;
    Callable Counter = new Counter();
    ExecutorService executor = newFixedThreadPool(AMOUNT_THRDS);

    for (int i = 0; i < 2; i++) {
        executor.submit(() -> {
            int rowSum = Counter.calcRow(i)
            Counter.increment(rowSum);
        })
    }

    executor.shutdown();

    try {
        executor.awaitTermination(1, TimeUnit.NANOSECONDS);
    }
    catch (e) {
    }

    system.out.println(Counter.call());
}