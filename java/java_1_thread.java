/*
*   Runnable & Thread extend
    - join
    - isAlive
*/

public static class MyThread extends Thread {
    @overrite
    public static void run() {
        system.out.println('hello from Thread');
    }

    public static void main(String args[]) {
        Thread ThreadInstance = new MyThread();
        ThreadInstance.join();

        if (ThreadInstance.isAlive()) {
            system.out.println("it's alive");
        }
    }
}
