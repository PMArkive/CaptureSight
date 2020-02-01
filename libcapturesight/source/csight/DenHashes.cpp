#include <switch.h>
#include <DenHashes.hpp>

u64 eventHash = 1721953670860364124u;

u64 denHashes[DEN_LIST_SIZE][2] = {
    {1675062357515959378u, 13439833545771248589u}, {1676893044376552243u, 13440787921864346512u}, {1676899641446321509u, 4973137107049022145u},
    {1676044221399762576u, 13438834089701394015u}, {1676051917981160053u, 13438837388236278648u}, {1676897442423065087u, 13440790120887602934u},
    {1676908437539347197u, 13440789021375974723u}, {1676046420423018998u, 13438839587259535070u}, {1676899641446321509u, 4973137107049022145u},
    {1677896898492919661u, 13439825849189851112u}, {1677881505330124707u, 1677895798981291450u},  {1677896898492919661u, 13439826948701479323u},
    {1676051917981160053u, 4973134908025765723u},  {1677896898492919661u, 13439825849189851112u}, {1676045320911390787u, 13438832990189765804u},
    {1676049718957903631u, 13438838487747906859u}, {1676048619446275420u, 13438843985306047914u}, {1676908437539347197u, 13440789021375974723u},
    {1676899641446321509u, 13439823650166594690u}, {1676899641446321509u, 13439823650166594690u}, {1676055216516044686u, 13441642242399277234u},
    {1676055216516044686u, 13441642242399277234u}, {1679871621376808167u, 13438843985306047914u}, {1676048619446275420u, 13438843985306047914u},
    {1676055216516044686u, 4973136007537393934u},  {1676895243399808665u, 1676891944864924032u},  {1676907338027718986u, 13440787921864346512u},
    {1676056316027672897u, 4973136007537393934u},  {1679872720888436378u, 13441636744841136179u}, {1679872720888436378u, 13441636744841136179u},
    {1676050818469531842u, 13438837388236278648u}, {1676046420423018998u, 13438842885794419703u}, {1675061258004331167u, 13438834089701394015u},
    {1675057959469446534u, 13438845084817676125u}, {1675056859957818323u, 13438840686771163281u}, {1675061258004331167u, 4972148646095449681u},
    {1675056859957818323u, 4972140949514052204u},  {1675055760446190112u, 13438839587259535070u}, {1679872720888436378u, 13441636744841136179u},
    {1677880405818496496u, 13439824749678222901u}, {1679872720888436378u, 13441636744841136179u}, {1677880405818496496u, 13439824749678222901u},
    {1677880405818496496u, 4973141505095534989u},  {1675055760446190112u, 13438839587259535070u}, {1675060158492702956u, 13438832990189765804u},
    {1676898541934693298u, 13439824749678222901u}, {1677894699469663239u, 13439829147724735745u}, {1679873820400064589u, 13440789021375974723u},
    {1676894143888180454u, 4972147546583821470u},  {1675059058981074745u, 4973140405583906778u},  {1676056316027672897u, 13438843985306047914u},
    {1675062357515959378u, 13439833545771248589u}, {1679873820400064589u, 13440789021375974723u}, {1676051917981160053u, 4973134908025765723u},
    {1676050818469531842u, 13438837388236278648u}, {1676891944864924032u, 13440791220399231145u}, {1677895798981291450u, 13439825849189851112u},
    {1679873820400064589u, 13440794518934115778u}, {1676046420423018998u, 4972146447072193259u},  {1676044221399762576u, 13438834089701394015u},
    {1675065656050844011u, 4972145347560565048u},  {1676049718957903631u, 13438842885794419703u}, {1677895798981291450u, 13439825849189851112u},
    {1676045320911390787u, 13438832990189765804u}, {1675057959469446534u, 4972142049025680415u},  {1677892500446406817u, 13439830247236363956u},
    {1675060158492702956u, 13438832990189765804u}, {1675064556539215800u, 13439831346747992167u}, {1676895243399808665u, 1676891944864924032u},
    {1675063457027587589u, 4973133808514137512u},  {1675063457027587589u, 13439833545771248589u}, {1675061258004331167u, 4973133808514137512u},
    {1676055216516044686u, 13441642242399277234u}, {1675056859957818323u, 13438840686771163281u}, {1675055760446190112u, 13438839587259535070u},
    {1677889201911522184u, 13439830247236363956u}, {1675064556539215800u, 13439831346747992167u}, {1677881505330124707u, 13438842885794419703u},
    {13440791220399231145u, 4973139306072278567u}, {1679871621376808167u, 13440795618445743989u}, {13440791220399231145u, 13440793419422487567u},
    {1677895798981291450u, 13440798916980628622u}, {1677893599958035028u, 13441641142887649023u}, {1675057959469446534u, 13438845084817676125u},
    {1676896342911436876u, 13439823650166594690u}, {1676898541934693298u, 13439828048213107534u}, {1675065656050844011u, 13439832446259620378u},
    {1677891400934778606u, 13441640043376020812u}, {1676897442423065087u, 13440790120887602934u}, {1675060158492702956u, 13440792319910859356u},
    {1676898541934693298u, 13439824749678222901u}, {1677891400934778606u, 13439830247236363956u}, {1675064556539215800u, 13440800016492256833u},
    {1676896342911436876u, 4973138206560650356u},  {1677894699469663239u, 4972151944630334314u},  {1677893599958035028u, 13439829147724735745u},
    {1675064556539215800u, 4972150845118706103u},  {1676056316027672897u, 13438843985306047914u}, {1676894143888180454u, 13441643341910905445u},
};