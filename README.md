# BasicOpenGLProject
Project : Pong Game

I created a pong game using FreeGlut and Visual Studio. I used the basic OpenGL
template provided in CatCourses. I am responsible for the logic and development of all the code.
This is a 1-person project. I created a Paddle class, a UserPaddle class, a OtherPaddle class, a
Ball class, and a Game class. Paddle class is an abstract class with pure virtual functions such as
PaddleUp(), PaddleDown(), Render(). UserPaddle and OtherPaddle are the derived classes and
hold the protected variables from the Paddle class which are posX and posY. I made the
destructor of the abstract class virtual, so the derived class’s destructor is invoked when the
abstract class pointer pointing toward the derived object is deleted : Paddle* dyn_ptr = new
UserPaddle(-0.97f,-0.25f); delete dyn_ptr; I also implemented upcasting : OtherPaddle
paddle2(0.92f,-0.25f); Paddle* uc_ptr = &paddle2;. As for my other classes, I added a Game
object as a member variable of the Ball class, so immediately after the ball collides with a paddle
or wall, the score is calculated. I created constructors and destructors for every class. Given that I
am using a Game* member variable, I added a delete pointer line in the destructor of the Ball
class. I used setters to change the bools in the Game object from the Ball class. I used getters to
get coordinate input from the Paddle and Ball class into the Collision function in Game class.

For rendering the rectangles, I used the OpenGL commands glColor3f and glRectf. I used
posX and posY as one vertex of the rectangle. I added float values for the opposite vertex to alter
the length and width of the rectangle. I also used the OpenGL commands glBegin(GL_LINES),
glEnd(), and glVertex2f to create dashed lines given that the origin exists in the center and the
y-axis range is -1 to 1. For the ball, I used OpenGL commands glutSolidSphere which takes the
radius and large values for 2nd/3rd parameters to make the circle rounder. This command
assumes the ball is placed in the origin, so I had to use glTranslatef to add the circle’s
coordinates. glPushMatrix() and glPopMatrix() were used to save those coordinates. To print the
score on the screen, I had to use glRasterPos2f to play the scores in the correct position. I also
had to use glutBitmapString to pick font/size and I had to convert the integer score into a char*
to fit the command’s parameter. The rest of the OpenGL commands such as glutWindowPosition
and glutSwapBuffers() are from the CatCourses basic OpenGL project template. I used version
control : git status, git add ., git commit -m “message”, and then I pushed the modified files into
the Github.


I implemented algorithm logic for collision detection and score calculation. For collision
detection, I first focused on how to determine whether the circle collides with the walls. The
OpenGL coordinate system is that the y-axis is -1 to 1 and the x-axis is -1 to 1. The left side of
the visible window is when x = -1. The right side of the visible window is when x=1. The top
side of the visible window is when y=1 and the bottom side of the visible window is when y =-1.
To move the ball, I created two equations that each control the ball’s movement in the x or y
direction. To save the current states of the movement, I added vx and vy as member variables of
the Ball class and those velocities are the slopes of the equations. Whenever the ball hits the
sides of the window, I would reverse the direction of motion by multiplying one of the velocities
with -1. I would also reset the x or y position, so the ball does not repeatedly trigger the collision
condition as it is moving backwards. I then focused on determining when the ball collides with
the paddles. The objective was to find the closest vertex on the rectangle to the circle’s center. I
determined that in each of the four sides of the rectangle, all the points on a side shared an x or y
coordinate. I created if-then statements on which side the circle is next to because it is only
possible the circle is on the right of the rectangle’s right side or the circle is below the rectangle’s
bottom side. Once I knew which side the circle is on, I knew what the common x or y coordinate
would be for that side and the other coordinate would be the same as the circle’s respective
coordinate. I then used the distance formula which is the square root of the sum of squared
differences of x and y coordinates. I used that function’s output as input for the BallMove
function. I used a series of bools. When the ball collides with a paddle, the bool for that paddle is
marked true and the bool for the other paddle is marked false. I wanted a win to be possible even
after the ball hits the top and bottom sides so I did not reset bool values if the ball collided there.
When the ball hit the left side, the bool for OppWallOther was marked true, meaning the other
paddle managed to directly or indirectly hit the ball toward the opposite wall. I applied the same
logic for the user’s paddle.
