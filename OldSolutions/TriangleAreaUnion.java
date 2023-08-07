import java.awt.geom.Area;
import java.awt.geom.Path2D;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class TriangleAreaUnion {
  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);

    int cases = sn.nextInt();
    for (int testCase = 0; testCase < cases; testCase++) {
      int n, d, h;
      n = sn.nextInt();
      d = sn.nextInt();
      h = sn.nextInt();
      ArrayList<Path2D.Double> triangles = new ArrayList<Path2D.Double>();

      for( int i = 0; i < n; i++ ) {
        int y = sn.nextInt();
        Path2D.Double triangle = createTriangle(0, y+h, -d/2.0, y, d/2.0, y);
        triangles.add(triangle);
      }
      Area area = new Area(triangles.get(0));
      for( int i = 1; i < triangles.size(); i++ ) {
        area.add(new Area(triangles.get(i)));
      }
      double unionArea = area.getBounds2D().getWidth() * area.getBounds2D().getHeight();
      System.out.println(unionArea);
    }
    sn.close();
  }

  private static Path2D.Double createTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    Path2D.Double triangle = new Path2D.Double();
    triangle.moveTo(x1, y1);
    triangle.lineTo(x2, y2);
    triangle.lineTo(x3, y3);
    triangle.closePath();
    return triangle;
  }
}
