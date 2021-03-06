#include "Item.hpp"
#include "../../../../utils/defines.hpp"
#include "CT.hpp"
#include "IHeal.hpp"
#include "IOpBox.hpp"

UNS

  namespace OpMon {
    namespace Model {

        Item *Item::itemsLst[ITEM_NUMBER] = {0};

        void initItems() {
            //For each item, add an enumeration entry in Items
            /*Item::itemsLst[0] = new I_Heal("Baie Oran", true, true, true, BagCat::BAIES, 10, Status::NOTHING, false, 0);
	Item::itemsLst[1] = new I_Heal("Baie Sitrus", true, true, true, BagCat::BAIES, 30, Status::NOTHING, false, 1);
	Item::itemsLst[2] = new I_Heal("Baie Mepo", true, true, true, BagCat::BAIES, 10, false, 2);
	Item::itemsLst[3] = new I_Heal("Baie Prine", true, true, true, BagCat::BAIES, 0, Status::POISONED, true, 3);
	Item::itemsLst[4] = new I_Heal("Baie Willia", true, true, true, BagCat::BAIES, 0, Status::FROZEN, false, 4);
	Item::itemsLst[5] = new I_Heal("Baie Fraive", true, true, true, BagCat::BAIES, 0, Status::BURNING, false, 5);
	//Jusqu'a 24 : Baies (Pas de baies de soin conditionnel, pas de baies autres
	Item::itemsLst[25] = new I_Heal("Défense +", Stats::DEF, 25);
	//Jusqu'a 31 : Stats+ sauf Muscle +
	Item::itemsLst[32] = new Item("Améliorator", false, false, true, BagCat::OBJECTS, 32);
	//Jusqu'a 42 : Objets evolution / echange a tenir
	Item::itemsLst[43] = new Item("Pierre Eclat", true, false, true, BagCat::OBJECTS, 43);
	//Jusqu'a 51 : Pierres evolutives
	Item::itemsLst[52] = new Item("Petit Champi", false, false, true, BagCat::OBJECTS, 52);
	//Jusqu'a 71 : Items a vendre
	//itemsLst[] = new const) Items d'amélioration d'EV. Classe a ajouter.
	//Jusqu'a 82 : Items d'amélioration d'EV (Sauf : Aile Sprint, Pilule Talent, Aile Mental, Aile Esprit, Aile Santé)
	Item::itemsLst[83] = new I_Heal("Soda Cool", true, true, true, BagCat::HEAL, 60, 83);
	//Jusqu'a 95 : Items de soin PV
	Item::itemsLst[96] = new I_Heal("Huile", true, true, true, BagCat::HEAL, 10, false, 96);
	//Jusqu'a 99 : Items de soin de PP
	//itemsLst[] = new const I_Heal("Rappel", TODO)) Items de Rappel a faire
	//Jusqu'a 103 : Items de Rappel
	Item::itemsLst[104] = new I_Heal("Galette Illumis", true, true, true, BagCat::HEAL, 0, Status::POISONED, true, 104);
	//Jusqu'a 114 : Items de Soin de Status
	Item::itemsLst[115] = new I_OpBox("Poké Ball", 1, 115);
	//Jusqu'a 124 : Balls classiques (+ Memoire Ball + HonorC:\Users\_le_pichon\Downloads\PPR\srcCpp\jlppc\regimys\objects\item\Item.cpp|66|error: expected type-specifier before 'I_Heal'| ball + Reve ball)
	//itemsLst[] = new const...) TODO Opballs spécialesC:\Users\_le_pichon\Downloads\PPR\srcCpp\jlppc\regimys\objects\item\Item.cpp|66|error: expected type-specifier before 'I_Heal'|
	//Jusqu'a 133 : Balls spéciales
	//Ensuite items TODO : Jusqu'a 136 : Repousses
	//137 : Corde Sortie
	//Jusqu'a 140 : Objets permettant de s'enfuir poké  sauvage
	//Enfin, tout ce qui est Item a tenir.
	Item::itemsLst[150] = new Item("Croc Rasoir", false, false, true, BagCat::OBJECTS, 3);//En fait 3 c'est ???
	//Jusqu'aux ct : Item a tenir
	//Après: CT*/
            //NINTENDO(c)
        }

        Item::Item(string name, bool usable, bool usableInFight, bool givable, BagCat categorie, int id)
          : name(name) {
            this->usable = usable;
            this->usableInFight = usableInFight;
            this->id = id;
            this->givable = givable;
            this->categorie = categorie;
        }

        Item *Item::getItem(string const &name) {
            for(unsigned int i = 0; i < ITEM_NUMBER; i++) {
                if(itemsLst[i] != nullptr) {
                    if(itemsLst[i]->getName() == name) {
                        return itemsLst[i];
                    }
                }
            }
            return itemsLst[0]; //Default
        }

        Item *Item::getItem(int id2) {
	  unsigned int id = ((id2 >= 0 && id2 < ITEM_NUMBER )? id2 : 0);
            if(itemsLst[id] != nullptr) {
                return itemsLst[id];
            } else {
                return itemsLst[0];
            }
        }

        int Item::searchItem(Item *toSearch) {
            for(unsigned int i = 0; i < ITEM_NUMBER; i++) {
                if(toSearch == itemsLst[i]) {
                    return i;
                }
            }
            return -1;
        }

        bool Item::operator==(Item const &b) const {
            if(categorie != b.categorie) {
                return false;
            }
            if(givable != b.givable) {
                return false;
            }
            if(!(name == b.name)) {
                return false;
            }
            if(usable != b.usable) {
                return false;
            }
            if(usableInFight != b.usableInFight) {
                return false;
            }
            if(id != b.id) {
                return false;
            }
            return true;
        }

    } // namespace Model
}
