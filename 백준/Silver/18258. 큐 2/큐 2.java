import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String line;
        int n = Integer.parseInt(bf.readLine());
    	ListQueue<Integer> q = new ListQueue<>(2000001);
        while(n-- > 0)
        {
            line = bf.readLine().trim();
            String[] op = line.split(" ");
            if(op.length == 2)
            {
                q.push(Integer.parseInt(op[1]));
            }
            else
            {
                if(op[0].equals("pop"))
                {
                    Integer ret = q.pop();
                    if(ret == null)
                        bw.write("-1\n");
                    else
                        bw.write(ret+"\n");
                }
                else if(op[0].equals("size"))
                {
                	bw.write(q.size()+"\n");
                }
                else if(op[0].equals("empty"))
                {
                	if(q.isEmpty())
                    	bw.write("1\n");
                	else
                    	bw.write("0\n");
                }
                else if(op[0].equals("front"))
                {
                	if(q.isEmpty())
                    	bw.write("-1\n");
                    else
                    	bw.write(q.front()+"\n");
                }
                else if(op[0].equals("back"))
                {
                	if(q.isEmpty())
                    	bw.write("-1\n");
                    else
                    	bw.write(q.back()+"\n");
                }
            }
        }
        bw.flush();
        bw.close();
    }
}

class ListQueue<E>
{   
    private E[] queue;
    private int front, back, numItems;
    private final static int DEFAULT_CAPACITY = 64;
    
    public ListQueue()
    {
    	queue = (E[]) new Object[DEFAULT_CAPACITY];
        numItems = 0;
        front = 0;
        back = queue.length-1;
    }
    
    public ListQueue(int capacity)
    {
    	queue = (E[]) new Object[capacity];
        numItems = 0;
        front = 0;
        back = queue.length-1;
    }
    
    public void push(E x)
    {
    	if(isFull())
            return;
        
        back = (back+1) % queue.length;
        queue[back] = x;
        numItems++;
    }
    
    public E pop()
    {
    	if(isEmpty())
            return null;
        
        E ret = queue[front];
        front = (front+1) % queue.length; // if(++front == queue.length) front = 0;
        numItems--;
        return ret;
    }
    
    public E front()
    {
    	if(isEmpty())
            return null;
            
        return queue[front];
    }
    
    public E back()
    {
        if(isEmpty())
            return null;
        
        return queue[back];
    }
    
    public boolean isEmpty()
    {
    	return numItems <= 0;
    }
    
    public boolean isFull()
    {
    	return numItems >= queue.length;
    }
    
    public int size()
    {
        return numItems;
    }
}