using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Cells;

namespace JamesConnorMaguire_PROG2200_Assignment4_MazeRunning
{
    public partial class Form1 : Form
    {
        /*Initial Declarations*/
        private Cell[,] grid;
        private int xPosition = 0;
        private int yPosition = 0;
        Random randomGenerator = new Random();
        private int winX;
        private int winY;
        int timerTicks = 0;
        //C:\\Repos\\AOOP\\JamesConnorMaguire_PROG2200_Assignment4_MazeRunning\\JamesConnorMaguire_PROG2200_Assignment4_MazeRunning\\
        Image v = Image.FromFile("Victory.png");
        bool victory = false;

        /*Form Construction*/
        public Form1()
        {
            InitializeComponent();
            buildMaze();
            Invalidate();
            /*Random values selected for destination point.*/
            winX = randomGenerator.Next(0, 10);
            winY = randomGenerator.Next(0, 10);
        }
        /*Constructs primary maze, sets user in top corner.*/
        private void buildMaze()
        {
            grid = new Cell[10, 10];
            grid[0, 0] = new Cell(true, false, true, false, true);
            grid[0, 1] = new Cell(false, false, true, true, false);
            grid[0, 2] = new Cell(false, true, true, false, false);
            grid[0, 3] = new Cell(true, false, true, true, false);
            grid[0, 4] = new Cell(false, true, true, false, false);
            grid[0, 5] = new Cell(true, false, true, true, false);
            grid[0, 6] = new Cell(false, false, true, false, false);
            grid[0, 7] = new Cell(false, false, true, false, false);
            grid[0, 8] = new Cell(false, false, true, true, false);
            grid[0, 9] = new Cell(false, true, true, false, false);

            grid[1, 0] = new Cell(true, true, false, true, false);
            grid[1, 1] = new Cell(true, true, true, false, false);
            grid[1, 2] = new Cell(true, false, false, true, false);
            grid[1, 3] = new Cell(false, false, true, false, false);
            grid[1, 4] = new Cell(false, false, false, true, false);
            grid[1, 5] = new Cell(false, false, true, true, false);
            grid[1, 6] = new Cell(false, false, false, false, false);
            grid[1, 7] = new Cell(false, false, false, false, false);
            grid[1, 8] = new Cell(true, true, true, false, false);
            grid[1, 9] = new Cell(true, true, false, false, false);

            grid[2, 0] = new Cell(true, false, true, true, false);
            grid[2, 1] = new Cell(false, false, false, false, false);
            grid[2, 2] = new Cell(false, true, true, true, false);
            grid[2, 3] = new Cell(true, true, false, false, false);
            grid[2, 4] = new Cell(true, false, true, false, false);
            grid[2, 5] = new Cell(false, true, true, false, false);
            grid[2, 6] = new Cell(true, false, false, false, false);
            grid[2, 7] = new Cell(false, true, false, true, false);
            grid[2, 8] = new Cell(true, true, false, false, false);
            grid[2, 9] = new Cell(true, true, false, false, false);

            grid[3, 0] = new Cell(true, true, true, false, false);
            grid[3, 1] = new Cell(true, false, false, false, false);
            grid[3, 2] = new Cell(false, false, true, true, false);
            grid[3, 3] = new Cell(false, true, false, false, false);
            grid[3, 4] = new Cell(true, true, false, false, false);
            grid[3, 5] = new Cell(true, true, false, false, false);
            grid[3, 6] = new Cell(true, true, false, false, false);
            grid[3, 7] = new Cell(true, false, true, false, false);
            grid[3, 8] = new Cell(false, false, false, false, false);
            grid[3, 9] = new Cell(false, true, false, false, false);

            grid[4, 0] = new Cell(true, false, false, true, false);
            grid[4, 1] = new Cell(false, true, false, false, false);
            grid[4, 2] = new Cell(true, true, true, false, false);
            grid[4, 3] = new Cell(true, true, false, false, false);
            grid[4, 4] = new Cell(true, true, false, true, false);
            grid[4, 5] = new Cell(true, true, false, false, false);
            grid[4, 6] = new Cell(true, true, false, false, false);
            grid[4, 7] = new Cell(true, true, false, false, false);
            grid[4, 8] = new Cell(true, true, false, false, false);
            grid[4, 9] = new Cell(true, true, true, false, false);

            grid[5, 0] = new Cell(true, true, true, false, false);
            grid[5, 1] = new Cell(true, false, false, false, false);
            grid[5, 2] = new Cell(false, true, false, true, false);
            grid[5, 3] = new Cell(true, false, false, false, false);
            grid[5, 4] = new Cell(false, false, true, true, false);
            grid[5, 5] = new Cell(false, false, false, true, false);
            grid[5, 6] = new Cell(true, true, false, false, false);
            grid[5, 7] = new Cell(true, true, false, false, false);
            grid[5, 8] = new Cell(true, true, false, true, false);
            grid[5, 9] = new Cell(true, true, false, false, false);

            grid[6, 0] = new Cell(true, true, false, false, false);
            grid[6, 1] = new Cell(true, true, false, false, false);
            grid[6, 2] = new Cell(true, true, true, false, false);
            grid[6, 3] = new Cell(true, true, false, false, false);
            grid[6, 4] = new Cell(true, true, true, false, false);
            grid[6, 5] = new Cell(true, false, true, true, false);
            grid[6, 6] = new Cell(false, true, false, true, false);
            grid[6, 7] = new Cell(true, false, false, true, false);
            grid[6, 8] = new Cell(false, false, true, true, false);
            grid[6, 9] = new Cell(false, true, false, false, false);

            grid[7, 0] = new Cell(true, false, false, true, false);
            grid[7, 1] = new Cell(false, false, false, true, false);
            grid[7, 2] = new Cell(true, false, false, true, false);
            grid[7, 3] = new Cell(false, true, false, false, false);
            grid[7, 4] = new Cell(true, false, false, true, false);
            grid[7, 5] = new Cell(false, false, false, false, false);
            grid[7, 6] = new Cell(false, true, true, true, false);
            grid[7, 7] = new Cell(true, false, true, true, false);
            grid[7, 8] = new Cell(false, false, true, true, false);
            grid[7, 9] = new Cell(false, true, false, true, false);

            grid[8, 0] = new Cell(true, false, true, true, false);
            grid[8, 1] = new Cell(false, false, true, true, false);
            grid[8, 2] = new Cell(false, false, true, true, false);
            grid[8, 3] = new Cell(false, false, false, false, false);
            grid[8, 4] = new Cell(false, false, true, true, false);
            grid[8, 5] = new Cell(false, false, false, true, false);
            grid[8, 6] = new Cell(false, false, true, true, false);
            grid[8, 7] = new Cell(false, false, true, false, false);
            grid[8, 8] = new Cell(false, false, true, true, false);
            grid[8, 9] = new Cell(false, true, true, false, false);

            grid[9, 0] = new Cell(true, false, true, true, false);
            grid[9, 1] = new Cell(false, false, true, true, false);
            grid[9, 2] = new Cell(false, false, true, true, false);
            grid[9, 3] = new Cell(false, true, false, true, false);
            grid[9, 4] = new Cell(true, false, true, true, false);
            grid[9, 5] = new Cell(false, false, true, true, false);
            grid[9, 6] = new Cell(false, false, true, true, false);
            grid[9, 7] = new Cell(false, true, false, true, false);
            grid[9, 8] = new Cell(true, false, true, true, false);
            grid[9, 9] = new Cell(false, true, false, true, false);

        }
        
        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            Invalidate();
        }

        private void Form1_Paint_1(object sender, PaintEventArgs e)
        {
            if (victory)
            {
                e.Graphics.DrawImage(v, new Point(75,60));
            }

            int spaceInterval = 40;
            /*Determines painting from grid data*/
            for (int x = 0; x < 10; x++)
            {
                for(int y = 0; y < 10; y++)
                {
                    if(grid[x,y].up == true)
                    {
                        e.Graphics.DrawLine(Pens.DarkViolet, x*spaceInterval+20, y*spaceInterval+30, (x+1)*spaceInterval+20, y*spaceInterval+30);
                    }
                    if(grid[x,y].down == true)
                    {
                        e.Graphics.DrawLine(Pens.DarkViolet, x * spaceInterval + 20, y * spaceInterval + 30 + spaceInterval, (x + 1) * spaceInterval + 20, y * spaceInterval + 30 + spaceInterval);
                    }
                    if (grid[x,y].left == true)
                    {
                        e.Graphics.DrawLine(Pens.DarkViolet, x * spaceInterval + 20, y * spaceInterval + 30, x*spaceInterval + 20, y * spaceInterval + 30 + spaceInterval);
                    }
                    if (grid[x, y].right == true)
                    {
                        e.Graphics.DrawLine(Pens.DarkViolet, (x + 1) * spaceInterval + 20, y * spaceInterval + 30, (x+1)*spaceInterval + 20, y*spaceInterval+30+spaceInterval);
                    }
                    /*Paint User*/
                    if(grid[x,y].occupied == true)
                    {
                        Image i = Image.FromFile("Mouse2.png");
                        e.Graphics.DrawImage(i, (x*spaceInterval) + 22, (y * spaceInterval) + 32);
                    }
                    /*Paint Target*/
                    Image target = Image.FromFile("Cheese.png");
                    e.Graphics.DrawImage(target, (winX * spaceInterval) + 22, (winY * spaceInterval) + 32);
                }
               
            }
        }
        /*User controls*/
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Right)
            {
                MovePiece(xPosition + 1, yPosition, "Right");
            }
            else if(e.KeyCode == Keys.Left)
            {
                MovePiece(xPosition - 1, yPosition, "Left");
            }
            else if(e.KeyCode == Keys.Up)
            {
                MovePiece(xPosition, yPosition - 1, "Up");
            }
            else if(e.KeyCode == Keys.Down)
            {
                MovePiece(xPosition, yPosition + 1, "Down");
            }
        }
        /*Movement controls*/
        private void MovePiece(int x, int y, string motion)
        {

            if (!victory)
            {
                Cell currentCell = grid[xPosition, yPosition];
                Cell moveCell;
                try
                {
                    moveCell = grid[x, y];
                }
                catch (IndexOutOfRangeException)
                {
                    return;
                }
                if (motion == "Right")
                {
                    if (currentCell.right == false && moveCell.left == false)
                    {
                        MoveWorker(x, y);
                    }
                }
                else if (motion == "Left")
                {
                    if (currentCell.left == false && moveCell.right == false)
                    {
                        MoveWorker(x, y);
                    }
                }
                else if (motion == "Up")
                {
                    if (currentCell.up == false && moveCell.down == false)
                    {
                        MoveWorker(x, y);
                    }
                }
                else if (motion == "Down")
                {
                    if (currentCell.down == false && moveCell.up == false)
                    {
                        MoveWorker(x, y);
                    }
                }
                Invalidate();
                winCheck();
            }
        }
        /*Move worker class*/
        private void MoveWorker(int x, int y)
        {
            grid[xPosition, yPosition].occupied = false;
            grid[x, y].occupied = true;
            xPosition = x;
            yPosition = y;
            //Console.WriteLine(xPosition + "," + yPosition);
            
        }
        /*Victory Condition comparison*/
        private void winCheck()
        {
            if(xPosition == winX && yPosition == winY)
            {
                //MessageBox.Show("Congratulations, you solved the maze!");
                timer1.Interval = 1000;
                timer1.Start();

                xPosition = 0;
                yPosition = 0;
                winX = randomGenerator.Next(0, 10);
                winY = randomGenerator.Next(0, 10);
                buildMaze();
                Invalidate();
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if(timerTicks > 5)
            {
                victory = false;
                timer1.Stop();
                timerTicks = 0;
                Invalidate();
                //Console.WriteLine("Stopping timer");
                
            }
            else
            {
                victory = true;
                timerTicks++;
                Invalidate();
            }
            
            
        }
    }
}
