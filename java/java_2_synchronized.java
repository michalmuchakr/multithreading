public static class Counter {
    public static amount = 0;
    public static Object lock = new Object();

    public static synchronized void increment(int incrementBy) {
        amount += incrementBy;
    } 
}

public static class Counter {
    public static amount = 0;

    public static void increment(int incrementBy) {
        synchronized (lock) {
            amount += incrementBy;
        }
    } 
}

public class myThead extends Thread {
    public static void run() {
        system.out.println('Hello');
        Counter.increment();
    }
}

public static class mainProgramm {
    public static void main(String args[]) {
        Thread t = new myThead();
        t.start();
        t.join();
    }
}