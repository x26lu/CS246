Program Flow£º

class ConsoleWindow
{
public:  
        
   // constructor 
   ConsoleWindow();
       
   // Draws an ASCII character to given location on backbuffer.
   void     Draw(int nX, int nY, char chrAscii);

   // Draws text at given location on backbuffer.
   void     DrawText(int nX, int nY, const char* szText);
   
   // Gets the character at a given location on screen.
   char     GetASCIITile(int nX, int nY);
   
   // Flips buffers. Actually draws the entire screen 
   void     UpdateScreen();
   
   // Reads a key from keyboard.
   char     ReadKey();
     
private:
            
    HANDLE   GetActiveBuffer();
    // Hides cursor on-screen.
    void     HideCursor();   
  
    HANDLE  hBackBuffer;
    HANDLE  hFrontBuffer;    
    int     nActiveBuffer;
};

extern ConsoleWindow console;


Floor
	Variables:
		//Width: 79
		//Height: 25 + 5
		Character Player
		Character Enemies
		Chamber[] 5

Chamber
	Variables:
		startx
		starty
		lengthx
		lengthy
		chamberNum
	Method:
		void        Init(int newX, int newY, int newWidth, int newBreadth)
		{
			X = newX;
			Y = newY;
			Width = newWidth;
			Breadth = newBreadth;
		}
		void print()
		getters/setters

Character£¨Player/Enemy)
	Variables:
		int x
		int y
		Race
		symbol
		HP, Atk, etc
	Methods:
		Move£¨int x, int y)
		void Attack (Character)
		draw() //draw symbol at x.y
		getters/setters

Game(CC3k):
char PlayerASCII         = 0x01;    // ASCII Man
char DuckASCII           = 0x44;    // ASCII Duck
char VerticalWallASCII   = 0xBA;    // Vertical wall piece
char HorizontalWallASCII = 0xCD;    // Horizontal wall piece
char TopRightCornerASCII = 0xBB;    // Top right wall piece
char TopLeftCornerASCII  = 0xC9;    // Top left wall piece
char BotLeftCornerASCII  = 0xC8;    // Bottom right wall piece
char BotRightCornerASCII = 0xBC;    // Bottom left wall piece
char FloorTileASCII      = 0x2E;    // Floor tile 
 

while(1)
     {
         // Read key from keyboard
         char pressedKey = console.ReadKey();
         //    Update dungeon
         //    Draw dungeon
         floor.Draw();

         console.UpdateScreen();

     }

	Floor floor;








	Variables:
	Methods:

	Variables:
	Methods: