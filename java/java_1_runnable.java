public class MyRunnable implements Runnable {
    private static void run() {
        system.out.println('Hello from runnable');
    }

    public static void main(String args[]) {
        Runnable RunnableInstance = new MyRunnable();
        Thread ThreadInstance = new Thread(RunnableInstance);
        ThreadInstance.start();
        ThreadInstance.join();

        if (ThreadInstance.isAlive()) {
            system.out.println("it's alive");
        }
    }
}