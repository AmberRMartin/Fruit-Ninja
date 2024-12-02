/**
 * @file battleScreen.cpp
 * @author Amber Martin
 * @brief Definitions for creating the battle screen
 * @version 0.1
 * @date 2024-11-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "battleScreen.h"

/**
 * @brief Construct a new Battle Screen:: Battle Screen object
 * 
 */
BattleScreen::BattleScreen()
{

//Background and text
    backTexture.loadFromFile("Sprites/Battle_screen_background.png");
    if(!backTexture.loadFromFile("Sprites/Battle_screen_background.png"))
    {
        exit(1);
    }
    Background.setTexture(backTexture);
    Background.setPosition(200,0);

    font.loadFromFile("Minecraftia-Regular.ttf");
    PHpTxt.setFont(font);
    PManaTxt.setFont(font);


//ADJUST HERE TO SET TEA TO LEVEL ONE VALUES
    PHpTxt.setString("HP: 20/20");
    PManaTxt.setString("Tea: ?/?");

    PHpTxt.setScale(0.8, 0.8);
    PManaTxt.setScale(0.8,0.8);
    
    PHpTxt.setPosition(535,365);
    PManaTxt.setPosition(535,415);

    PHpTxt.setFillColor(sf::Color::Black);
    PManaTxt.setFillColor(sf::Color::Black);


//Buttons
    Button Temp1("Attack", {320,50},{194,55});
    Button Temp2("Skill", {570,50},{194,55});
    Attack = Temp1;
    Skill = Temp2;
    Attack.fixFiles();
    Skill.fixFiles();

    Button Temp3("Heal",{450,360}, {294, 45});
    Button Temp4("Slice", {450,410}, {294, 45});
    Button Temp5("Return", {450, 460}, {294, 45});
    
    Heal = Temp3;
    SkillAtk = Temp4;
    ReturnSkill = Temp5;
    Heal.fixFiles();
    SkillAtk.fixFiles();
    ReturnSkill.fixFiles();

//player stuff
    Players.loadFromFile("Sprites/player_battle_sprites.png");
    if(!Players.loadFromFile("Sprites/player_battle_sprites.png"))
    {
        exit(1);
    }

    PlayerN.setTexture(Players);
    PlayerA.setTexture(Players);
    PlayerD.setTexture(Players);
    PlayerN.setTextureRect(sf::IntRect({0,0}, {146,146}));
    PlayerA.setTextureRect(sf::IntRect({151,0},{146,146}));
    PlayerD.setTextureRect(sf::IntRect({304,0},{146,146}));

    PlayerN.setOrigin(73,73);
    PlayerN.setPosition({450, 415});
    PlayerA.setOrigin(73,73);
    PlayerA.setPosition({450, 415});
    PlayerD.setOrigin(73,73);
    PlayerD.setPosition({450, 415});
    

//Monster stuff
    Monsters.loadFromFile("Sprites/monster_battle_sprites.png");
    if(!Monsters.loadFromFile("Sprites/monster_battle_sprites.png"))
    {
        exit(1);
    }
//default monster is cherry
    MonsterN.setTexture(Monsters);
    MonsterA.setTexture(Monsters);
    MonsterD.setTexture(Monsters);

    MonsterN.setTextureRect(sf::IntRect({0,0},{292,192}));
    MonsterA.setTextureRect(sf::IntRect({292,0},{292,192}));
    MonsterD.setTextureRect(sf::IntRect({573,0},{292,192}));

    MonsterN.setOrigin({146,96});
    MonsterA.setOrigin({146,96});
    MonsterD.setOrigin({146,96});

    MonsterN.setPosition({450, 200});
    MonsterA.setPosition({450, 200});
    MonsterD.setPosition({450,200});

//Misc;
    SkillMenu = false;

}

/**
 * @brief Draw functions, changes on various bool variables
 * 
 * @param target 
 * @param states 
 */
void BattleScreen::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
//Defaults, MonsterN may need to be moved but background should be safe here
    target.draw(Background);
    target.draw(MonsterN);

    if(SkillMenu == false)
    {
        target.draw(PlayerN);
        target.draw(Attack);
        target.draw(Skill);
        target.draw(PHpTxt);
        target.draw(PManaTxt);
    }
    else if (SkillMenu == true)
    {
        target.draw(Heal);
        target.draw(SkillAtk);
        target.draw(ReturnSkill);
    }

//Add as many else ifs as neccessary
}

/**
 * @brief Updates visuals based on the various buttons
 * 
 * @param e 
 * @param window 
 */
void BattleScreen::update(sf::Event& e, sf::RenderWindow& window)
{
//Opening/Closing the skill menu
    if(Skill.clicked(e, window))
    {
        SkillMenu = true;
    }
    else if (ReturnSkill.clicked(e, window))
    {
        SkillMenu = false;
    }

/*
IMPORTANT NOTE
There is 1 things that buttons do: return true if you click them
Thats it. That is their ONLY function. If you click inside, it returns true
Please do not change that function. It will break literally everything

Also note: you'll need to update hp and mana here too. no I don't know how, perhaps you can add
another function or change the header to add a stats variable?
*/
}

/**
 * @brief This is for when the player has leveled up, you can find this function under game.Glevelup();
 * 
 * @param stats 
 */
void BattleScreen::updateStats(Stats &stats)
{
    std::string hp = std::to_string(stats.getMaxHP());
    PHpTxt.setString("HP: " + hp + "/" + hp);
//this is what I assume mana looks like. fix whenever we have that function
//only thing that needs edited is the max mana name function
    //std::string mana = std::to_string(stats.getMaxMana());
    //PManaTxt.setString("Tea: " + mana + "/" + mana);
}

/**
 * @brief Changes the monster sprite
 * 
 * @param num Monster to change to
 */
void BattleScreen::ChangeMonster(int num)
{
    if (num == 0) //Cherry, also default
    {
        MonsterN.setTextureRect(sf::IntRect({0,0},{292,192}));
        MonsterA.setTextureRect(sf::IntRect({292,0},{292,192}));
        MonsterD.setTextureRect(sf::IntRect({573,0},{292,192}));
    }
    else if (num == 1) //Apple
    {
        MonsterN.setTextureRect(sf::IntRect({0,187},{292,192}));
        MonsterA.setTextureRect(sf::IntRect({292,187},{292,192}));
        MonsterD.setTextureRect(sf::IntRect({573,187},{292,192}));
    }
    else if (num == 2) //Orange
    {
        MonsterN.setTextureRect(sf::IntRect({0,374},{292,192}));
        MonsterA.setTextureRect(sf::IntRect({292,374},{292,192}));
        MonsterD.setTextureRect(sf::IntRect({573,374},{292,192}));
    }
    else if (num == 3) //Grapes
    {
        MonsterN.setTextureRect(sf::IntRect({0,556},{292,192}));
        MonsterA.setTextureRect(sf::IntRect({292,556},{292,192}));
        MonsterD.setTextureRect(sf::IntRect({573,556},{292,192}));
    }

/*
Okay so here's the thing:
If you need to change how this works. Just do it, it's fine
All of those lines are based on the actual positions of the sprites. They are already tested
and work for the actual display of the monsters, and are already scaled to correct size
. do not recommend changing those position or size numbers

*/
}