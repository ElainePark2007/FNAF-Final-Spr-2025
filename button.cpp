/**
 * @file button.cpp
 * @author Matteo Coppola, Luke Kellner, Elaine Park
 * @brief Button class definition file
 * @date 2025-05-07
 */
#include "button.h"

/**
 * @brief Construct a new Button:: Button object
 * 
 * @param s String for text
 * @param position Position of button
 * @param size Size of button
 * @param color Color of button
 */
Button::Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{

    // sf::Sprite mButton;
    // sf::Texture mTexture;
    // sf::Color mButtonColor;
    // sf::Vector2f mPosition;
    // sf::Uint32 mBtnState;
    // //text
    // sf::Text mText;
    // sf::Font mFont;
    // sf::Color mTextNormal;
    // sf::Color mTextHover;
    
    if (!mTexture.loadFromFile("button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    //create sprite that look like a button
    mButton.setTexture(mTexture);
    
    //get size of image
    sf::Vector2u imageSize=mTexture.getSize();
    //change origin to the center of the image (makes rotation easy)
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
    //set position
    mPosition=position;
    mButton.setPosition(mPosition.x,mPosition.y);
    //choose color
    mButtonColor=color;
    mButton.setColor(color);
    //set size as a ration of original size
    mButton.setScale(size.x/imageSize.x,size.y/imageSize.y);
    //Make label
    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    mText.setFont(mFont);
    //choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    //set label
    mText.setString(s);
    //set origin to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
    //choose colors
    mTextNormal = sf::Color::Green;
    mTextHover = sf::Color::Red;
    mText.setFillColor(mTextNormal);
    mBtnState=normal;
}
//Default constructor that loads texture from file “button.png” and font from “college.ttf” file.
    //set texture for mButton, set the origin to the middle of the button (texture), 
    //set color to White, position to {300,100}, set state to normal, and scale to 100%
    //set font for the text, set the size of the text to the half of Button size, set the origin to the middle of the text 
    //and set position at the middle of the button, assign “Push me!” as a string of the button
/**
 * @brief Construct a new Button:: Button object
 * 
 */
Button::Button() :Button("Push me!", sf::Vector2f({300,100}), sf::Vector2f({600,212}), sf::Color::White)
{

}

/**
 * @brief Sets text of button
 * 
 * @param s String for text
 */
void Button::setText(std::string s)
{
    mText.setString(s);
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
}

/**
 * @brief Sets position of button
 * 
 * @param position Coordinates for position
 */
void Button::setPosition(sf::Vector2f position)
{
    mPosition=position;
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mButton.setPosition(mPosition.x,mPosition.y);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
}

/**
 * @brief Sets size of button
 * 
 * @param size Size for button
 */
void Button::setSize(sf::Vector2f  size)
{
    sf::Vector2u imageSize=mTexture.getSize();
    mButton.setScale(size.x/imageSize.x,size.y/imageSize.y);
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);

}

/**
 * @brief Sets color of button
 * 
 * @param btnColor Color for button
 */
void Button::setColor(sf::Color btnColor)
{
    mButtonColor=btnColor;
    mButton.setColor(btnColor);
}

/**
 * @brief Updates button
 * 
 * @param e Event for button
 * @param window Window to display
 */
void Button::update(sf::Event& e, sf::RenderWindow& window)
{
    sf::Vector2i mPos = sf::Mouse::getPosition(window);
            sf::Vector2f mousePosition = window.mapPixelToCoords(mPos);
            bool mouseInButton =    mousePosition.x >= mButton.getPosition().x - mButton.getGlobalBounds().width/2
                                    && mousePosition.x <= mButton.getPosition().x + mButton.getGlobalBounds().width/2
                                    && mousePosition.y >= mButton.getPosition().y - mButton.getGlobalBounds().height/2
                                    && mousePosition.y <= mButton.getPosition().y + mButton.getGlobalBounds().height/2;
            if(e.type == sf::Event::MouseMoved)
            {
                if(mouseInButton)
                {
                    mText.setFillColor(mTextHover);
                }
                else
                {
                    mText.setFillColor(mTextNormal);
                }
            }
            if (e.type == sf::Event::MouseButtonPressed)
            {
                if(e.mouseButton.button==sf::Mouse::Left)
                {
                    if(mouseInButton)
                    {
                        mButton.setRotation(180);
                    }
                    else
                    {
                        mButton.setRotation(0);
                    }
                }
            }
            if (e.type == sf::Event::MouseButtonReleased)
            {
                if (e.mouseButton.button==sf::Mouse::Left)
                {
                    if(mouseInButton)
                    {
                        mText.setFillColor(mTextHover);
                        mButton.setRotation(0);
                    }
                    else
                    {
                        mText.setFillColor(mTextNormal);
                        mButton.setRotation(0);
                    }
                }
            }
}

/**
 * @brief Draws button
 * 
 * @param target Window to draw in
 * @param states State of button
 */
void Button::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(mButton, states);
    target.draw(mText, states);
}