using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cells
{
    class Cell
    {
        
        public bool up;
        public bool down;
        public bool left;
        public bool right;
        public bool occupied;

        public Cell(bool upValue, bool downValue, bool leftValue, bool rightValue, bool occupiedValue)
        {
            this.up = upValue;
            this.down = downValue;
            this.left = leftValue;
            this.right = rightValue;
            this.occupied = occupiedValue;
        }
        public void paint()
        {

        }
    }
}
