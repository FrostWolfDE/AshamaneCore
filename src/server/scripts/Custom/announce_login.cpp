#include "Config.h"
#include "World.h"

class announce_login : public PlayerScript
{
public:
    announce_login() : PlayerScript("announce_login") { }

    void OnLogin(Player* player, bool /*loginFirst*/)
    {
		if (sConfigMgr->GetBoolDefault("Login.Announcer.Enable", true))
		{
        if (player->GetTeam() == ALLIANCE)
                {
            std::ostringstream ss;
                        ss << "|cff3DAEFF[ Frost-Wolf.de ]|cffFFD800 : Spieler|cff4CFF00 " << player->GetName() << " |cffFFD800ist Online. Kämpft für die|cff0026FF Allianz";
            sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
                }
                else
                {
            std::ostringstream ss;
                        ss << "|cff3DAEFF[ Frost-Wolf.de ]|cffFFD800 : Spieler|cff4CFF00 " << player->GetName() << " |cffFFD800ist Online. Kämpft für die|cffFF0000 Horde" ;
            sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
                }
		}
    }
};

void AddSC_announce_login()
{
    new announce_login;
}