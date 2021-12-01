/*
 * Een bonus moet (tijdelijk) de toestand of het gedrag van een Entiteit wijzigen op een generieke en autonome manier,
 * zodat je gemakkelijk een nieuw bonustype kunt toevoegen, zonder noodzakelijkerwijs de interface van de Entiteiten
 * zelf te moeten veranderen. Deze logica moet daarom niet worden gecodeerd als een set_spring_bonus method in
 * bijvoorbeeld World of Player, maar eerder in de Bonus class zelf of een speciaal gebouwde klasse met een geschikte
 * levenscyclus. Hoe je dit specifiek implementeert is aan jou, ofwel door een unieke oplossing te ontwerpen of door
 * gebruik te maken van bestaande ontwerppatronen.
 */

#ifndef AP_DOODLE_GAME_EM_BONUS_H
#define AP_DOODLE_GAME_EM_BONUS_H

#include "Entity_Model.h"

class EM_Bonus : public Entity_Model{

};


#endif //AP_DOODLE_GAME_EM_BONUS_H