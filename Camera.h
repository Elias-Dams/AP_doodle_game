/*
 * Omdat de wereld dynamisch gecreëerd en vernietigd wordt op basis van de huidige positie van de speler,
 * moet het huidige zicht van de speler expliciet gemodelleerd worden, wat wordt gedaan door de Camera klasse.
 * De gehele wereld moet worden gemodelleerd met behulp van een genormaliseerd coördinatenstelsel,
 * dat zich oneindig in één richting uitstrekt. De camera wordt dan gebruikt om coördinaten die binnen
 * een rechthoek liggen, gedefinieerd over deze wereldruimte, te projecteren naar een onafhankelijk
 * coördinatensysteem dat vaste grenzen heeft. Het moet ook deze coördinaten herschalen zodat ze kunnen
 * worden gebruikt als pixelwaarden binnen het SFML-venster. Ook deze functionaliteit moet handmatig
 * worden geïmplementeerd, zonder gebruik te maken van SFML-hulpprogramma's.
 */

#ifndef AP_DOODLE_GAME_CAMERA_H
#define AP_DOODLE_GAME_CAMERA_H


class Camera {
public:
    Camera(float cameraWidth, float cameraHeight);

    float getHeight() const;

    float getHeightdiff() const;

    void setHeight(float height);

private:

    float CameraWidth;
    float CameraHeight;
    float height;
    float prev_height;
};


#endif //AP_DOODLE_GAME_CAMERA_H
