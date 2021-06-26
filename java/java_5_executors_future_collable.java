import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class myFuture implements Callable<String> {
    private int task_no;

    public myFuture(Integer Task_no) {
        this.task_no = Task_no;
    }

    public String call () {
        return ("Hello from task: " + task_no + " thread: " + Thread.currentThread.getName());
    }
}

public static void main(String args[]) {
    int AMOUNT_THRDS = 10;
    ExecutorService executor = Executors.newFixedThreadPool(AMOUNT_THRDS);

    List<Future<String>> list = new ArrayList<Future<String>>();

    for (int i = 0; i < 50; i++) {
        Callable<String> callable = new myFuture(i);
        Future<String> future = executor.submit(callable);

        list add(future);
    }

    for (Future<String> list_item : list) {
        // funkcja get przekazuje wyniki zwracany przez call
        System.out.println(list_item.get());
    }

    executor.shutdown();
}
