/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.awt.*;
import java.awt.Stroke;
import java.awt.Point;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import javax.swing.JPanel;
import java.awt.Graphics2D;
import java.awt.Dimension;
import javax.swing.border.*;
import javax.swing.*;
/**
 *
 * @author drogba
 */
public class PaintPanel extends JPanel{
    private BufferedImage src;
    private BufferedImage viev;
    private int zoom;
    private File srcFile;
    private File nextSrcFile;
    private Color lmbColor;
    private Color rmbColor;
    private Point start_point;
    private int mouse_x;
    private int mouse_y;
    private Icon down;
    
    public PaintPanel (){
        super();
        srcFile = new File("Herb_chelsea.jpg");
        lmbColor = Color.white;
        rmbColor = Color.black;
        try{
            src = ImageIO.read(srcFile);
            viev = ImageIO.read(srcFile);
        } catch (IOException e){
            
        }
        
        zoom = 1;
        
         Dimension size = new Dimension(src.getWidth(), src.getHeight());
         setPreferredSize(size);
         
    }
     
    protected int get_zoom(){
        return zoom;
    }
    @Override
    protected void paintComponent(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        
        g2d.drawImage(viev, 0, 0, this); // see javadoc for more info on the parameters            
    }
    
    protected void zoom_inc(){
        if(zoom < 8)
            zoom++;
    }
    
    protected void zoom_dec(){
        if(zoom > 1)
            zoom--;
    }
    
    protected void reload_viev(){
        
        if(srcFile != nextSrcFile && nextSrcFile != null){
            try{
                srcFile = nextSrcFile;
                src = ImageIO.read(srcFile);
            }catch(IOException e){}
            
        }
        
        int newImageWidth = src.getWidth() * zoom;
        int newImageHeight = src.getHeight() * zoom;
        viev = new BufferedImage(newImageWidth , newImageHeight, src.getType());
        Graphics2D g = viev.createGraphics();
        g.drawImage(src, 0, 0, newImageWidth , newImageHeight , null);
        g.dispose();
        Dimension size = new Dimension(newImageWidth, newImageHeight);
        setPreferredSize(size);
        repaint();
    }
    
    protected void draw(Point point, boolean left) {
    
        if(left)
            src.setRGB(point.x/zoom, point.y/zoom, lmbColor.getRGB());
        else
            src.setRGB(point.x/zoom, point.y/zoom, rmbColor.getRGB());

        for(int i = 0; i < zoom; i++){
            for(int j = 0; j < zoom; j++){
                if(left)
                    viev.setRGB((point.x/zoom)*zoom + i, (point.y/zoom)*zoom + j, lmbColor.getRGB());
                else
                    viev.setRGB((point.x/zoom)*zoom + i, (point.y/zoom)*zoom + j, rmbColor.getRGB());
            }
        }
    }
    
    protected BufferedImage get_src(){
        return src;
    }
  
    
    protected void load_File(String path){
        nextSrcFile = new File(path);
    }
    
    protected void set_leftColor(Color c){
        lmbColor = c;
    }
     protected void set_rightColor(Color c){
        rmbColor = c;
    }
    
    protected void set_startpoint(Point p){
        start_point=p;
    }
    
}
