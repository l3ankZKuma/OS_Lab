public class Q5WaitNotifyDriver {
    public static void main(String[] args) {
            SharedNum5 sn = new SharedNum5();
            // unnamed thread receiver
            /* Thread recver = */ (new Thread(new Runnable() {
            @Override
            public void run() {
            System.out.println("got " + sn.getVal());
            }
            })).start();
            try {
            Thread.sleep(2); // main
            } catch (InterruptedException ie) { }
            // unnamed thread sender 
            /* Thread sender = */ (new Thread(new Runnable() {
            @Override
            public void run() {
            sn.setVal(2021);
            }
            })).start();
            // since no reference do not care for join
            System.out.println("from main");
            }
}
   class SharedNum5 {
            private int val = 0;
            Object lock;
            SharedNum5() {
            val = 0;
            }
            synchronized int getVal() {
                    try {
                    System.out.println("waiting");
                    // waiting for notify from setVal
                    this.wait();
                    } catch (InterruptedException ie) { }
                    return val;
            } // getVal
                synchronized void setVal(int x) {
                        val = x;
                        this.notifyAll();
            } // setVal
   }
   