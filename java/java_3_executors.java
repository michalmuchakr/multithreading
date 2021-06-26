include java.util.concurent.Executors;
include java.util.concurent.ExecutorService;

public static class Counter {
    public static amount = 0;
    public static Object lock = new Object();

    public static synchronized void increment(int incrementBy) {
        amount += incrementBy;
    }
}

public static class ExecutorExample {
    public static int THREAD_AMOUNT = 10;
    public Counter cnt = new Counter();

    Executor executor = ExecutorService.newFixedThreadPool(THREAD_AMOUNT);

    for (int i=0; i<50; i++) {
        Runnable zwiekszaczLicznikow = new ZwiekszaczLicznikow(licznik);
        executor.execute(zwiekszaczLicznikow);
    }

    executor.shutdown();
    while (!executor.isTerminated()) {}
}