import java.awt.Robot;
import java.io.ObjectInputStream.GetField;
import java.io.PrintWriter;
import java.util.Scanner;
import javax.swing.text.StyledEditorKit.ForegroundAction;
import javax.xml.bind.annotation.adapters.HexBinaryAdapter;
import javax.xml.stream.StreamFilter;

public class robot {

    double Distance, Direction, DistChng, DirChng, BodyDir, HeadDir;
    public void see(String[] originStr, int i){
    
        String time = originStr[i+1];
        System.out.print("在"+ time +"周期" + " see ");
    
    }
    public void ball(String []originStr, int i){
   
        i=i+2;
        System.out.println(originStr[i]);
        double []data = new double[4];
        for(int y=0;y<4;i++,y++)
        {
            data[y]=Double.parseDouble(originStr[i]);
        } 
        Distance=data[0];
        Direction=data[1];
        DistChng = data[2];
        DirChng =data[3];
        System.out.println(  " Ball 距离我的 Distance 是 "+Distance+" Direction是"+Direction+" DistChng是"+DirChng+"  DirChng是"+DirChng);


    }
    public void Player(String []originStr, int i){
        String[] playerName = new String[2];
        int x;
        
        playerName[0] = originStr[i+1];
        playerName[1] = originStr[i+2];

        x = i+4;
        double []data = new double[6];
        for(int y=0;y<6;x++,y++)
        {
            data[y]=Double.parseDouble(originStr[x]);
        } 
    
        Distance=data[0];
        Direction=data[1];
        DistChng = data[2];
        DirChng = data[3];
        BodyDir = data[4];
        HeadDir = data[5];
    
        System.out.println( originStr[i+1]+" "+originStr[i+2]+"  距离我的 Distance 是 "+Distance+"  Direction是"+Direction+"  DistChng是"+ DistChng+"  DirChng是"+DirChng);   
    
    }
  
    public void goal(String []originStr,int i){
    
        int x=i+3;
        double []data = new double[2];
        for(int y=0;y<2;x++,y++)
        {
            data[y]=Double.parseDouble(originStr[x]);
        } 
        Distance=data[0];
        Direction=data[1];
    
        System.out.print( "goal "+originStr[i+1]+ "  距离我的 Distance 是 "+Distance+"  Direction是"+Direction);
   
    }
    public void hear(String[]originStr){
        int i=0;
        for(;i<originStr.length;i++)
        {
            if(originStr[i].equals("hear"))
            break;
        }

        String time = originStr[i+1];
        System.out.print("在"+time+"周期"+"  hear ");
    
   }
   
    public void sender(String[]originStr,int x){
    
        int i=0;
        for(;i<originStr.length;i++)
        {
            if(originStr[i].equals("passto"))
            break;
        }
   
        System.out.print("从"+originStr[x+2]+"方向听到了"+"passto("+originStr[i+1]+","+originStr[i+2]+")"); 
    
    }
    public static void main(String[] args) {    
        robot Robot = new  robot();
        Scanner in = new Scanner(System.in);       
        String str=in.nextLine();      
        String originStr2=str.replaceAll("\\(|\\)", "\\,"); 
        String[] originStr=originStr2.split("\\s+|\\,"); 
        

        for(int y=0;y<originStr.length;y++)
        {
            if(originStr[y].equals("hear")){
            Robot.hear(originStr);
            Robot.sender(originStr,y);
            System.out.println("");
            }
            else if(originStr[y].equals("see")){
                Robot.see(originStr,y);}
            else if(originStr[y].equals("ball")){
                Robot.ball(originStr,y);}
            else if(originStr[y].equals("player")){
            Robot.Player(originStr,y);}
            else if(originStr[y].equals("goal")){
            Robot.goal(originStr,y);}

        }  
    }                    
}
  























