#pragma once
#include <array>

#include "Engine/mm7_data.h"
#include "Engine/IocContainer.h"
#include "Engine/Strings.h"

#include "Engine/Graphics/BSPModel.h"
#include "Engine/Graphics/IRender.h"
#include "Engine/Graphics/IndoorCameraD3D.h"

using EngineIoc = Engine_::IocContainer;

/*  358 */
#pragma pack(push, 1)
struct LightsData {
    int field_0;
    Plane_int_ plane_4;
    Vec3_int_ vec_14;
    Vec3_int_ vec_20;
    unsigned int uCurrentAmbientLightLevel;
    int field_30;
    int field_34;
    int field_38;
    int pDeltaUV[2];
    int field_44;
    int field_48;
    char field_4C[8];
    Vec3_int_ rotated_normal;
    Vec3_int_ vec_60;
    int field_6C;
    Vec3_int_ vec_70;
    int field_7C;
    Vec3_int_ vec_80;
    Vec3_int_ vec_8C;
    int field_98;
    Vec3_int_ vec_9C;
    int field_A8;
    unsigned int uNumLightsApplied;
    int _blv_lights_radii[20];
    int _blv_lights_inv_radii[20];
    int _blv_lights_xs[20];
    int _blv_lights_ys[20];
    int _blv_lights_light_dot_faces[20];
    int field_240;
    int field_244;
    int field_248;
    int field_24C;
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
    int field_260;
    int field_264;
    int field_268;
    int field_26C;
    int field_270;
    int field_274;
    int field_278;
    int field_27C;
    int field_280;
    int field_284;
    int field_288;
    int field_28C;
    int _blv_lights_zs[20];
    float _blv_lights_rs[20];
    float _blv_lights_gs[20];
    float _blv_lights_bs[20];
    char _blv_lights_types[20];
    int field_3E4;
    int field_3E8;
    int field_3EC;
    int field_3F0;
    int field_3F4;
    unsigned int uDefaultAmbientLightLevel;
};
#pragma pack(pop)

extern LightsData Lights;  // idb

#pragma pack(push, 1)
struct DDM_DLV_Header {
    //----- (00462607) --------------------------------------------------------
    inline DDM_DLV_Header() {
        this->uLastRepawnDay = 0;
        this->uNumRespawns = 0;
        this->uReputation = 0;
        this->field_C_alert = 0;
        this->uNumFacesInBModels = 0;
        this->uNumDecorations = 0;
        this->uNumBModels = 0;
    }

    int uNumRespawns;
    int uLastRepawnDay;
    int uReputation;
    int field_C_alert;
    unsigned int uNumFacesInBModels;
    unsigned int uNumDecorations;
    unsigned int uNumBModels;
    int field_1C;
    int field_20;
    int field_24;
};
#pragma pack(pop)

/*  345 */
#pragma pack(push, 1)
struct stru315 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    uint16_t *field_34_palette;
    uint16_t *pTextureLOD;
    unsigned int *pDepthBuffer;
    uint16_t *pColorBuffer;
};
#pragma pack(pop)

/*  346 */
#pragma pack(push, 1)
struct stru316 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    uint16_t *field_24_palette;
};
#pragma pack(pop)

/*  134 */
#pragma pack(push, 1)
struct stru141_actor_collision_object {
    int _47050A(int a2);

    int field_0;
    int prolly_normal_d;
    int field_8_radius;
    int height;
    int field_10;
    int field_14;
    int field_18;
    Vec3_int_ velocity;
    Vec3_int_ normal;
    Vec3_int_ position;
    Vec3_int_ normal2;
    int field_4C;
    int field_50;
    int field_54;
    Vec3_int_ direction;  // velocity's unit vector
    int speed;
    int inv_speed;
    int field_6C;
    int field_70;
    unsigned int uSectorID;
    unsigned int pid;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int sMaxX;
    int sMinX;
    int sMaxY;
    int sMinY;
    int sMaxZ;
    int sMinZ;
    int field_A4;
};
#pragma pack(pop)
extern stru141_actor_collision_object stru_721530;

/*  378 */
#pragma pack(push, 1)
struct stru337_stru0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
};
#pragma pack(pop)

/*  377 */
#pragma pack(push, 1)
struct stru337 {
    stru337_stru0 field_0;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    stru337_stru0 field_34;
};
#pragma pack(pop)
extern stru337 stru_F81018;

/*  291 */
enum PolygonType : uint8_t {
    POLYGON_Invalid = 0x0,
    POLYGON_VerticalWall = 0x1,
    POLYGON_unk = 0x2,
    POLYGON_Floor = 0x3,
    POLYGON_InBetweenFloorAndWall = 0x4,
    POLYGON_Ceiling = 0x5,
    POLYGON_InBetweenCeilingAndWall = 0x6,
};

/*  147 */
#pragma pack(push, 1)

struct stru154 {
    //----- (0049B001) --------------------------------------------------------
    inline stru154() {}

    //----- (0049B027) --------------------------------------------------------
    inline ~stru154() {}

    void GetFacePlaneAndClassify(struct ODMFace *a2,
                                 struct BSPVertexBuffer *a3);
    void ClassifyPolygon(struct Vec3_float_ *pNormal, float dist);
    void GetFacePlane(struct ODMFace *pFace, struct BSPVertexBuffer *pVertices,
                      struct Vec3_float_ *pOutNormal, float *pOutDist);

    void (***vdestructor_ptr)(stru154 *, bool);
    Plane_float_ face_plane;
    PolygonType polygonType;
    char field_15;
    char field_16;
    char field_17;
};
#pragma pack(pop)

/*  392 */
#pragma pack(push, 1)
struct stru352 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
};
#pragma pack(pop)
// extern std::array<stru352, 480> stru_F83B80;

#pragma pack(push, 1)
struct LocationTime_stru1 {
    GameTime last_visit;
    char sky_texture_name[12];
    int day_attrib;
    int day_fogrange_1;
    int day_fogrange_2;
    char field_2F4[24];
};
#pragma pack(pop)

/*  319 */
enum LEVEL_TYPE {
    LEVEL_null = 0,
    LEVEL_Indoor = 0x1,
    LEVEL_Outdoor = 0x2,
};
extern LEVEL_TYPE uCurrentlyLoadedLevelType;

/*   86 */
#pragma pack(push, 1)
struct SpawnPointMM6 {
    Vec3_int_ vPosition;
    uint16_t uRadius;
    uint16_t uKind;
    uint16_t uIndex;
    uint16_t uAttributes;
};
#pragma pack(pop)

/*  102 */
#pragma pack(push, 1)
struct SpawnPointMM7 {
    //----- (00448DD6) --------------------------------------------------------
    SpawnPointMM7() {
        uRadius = 32;
        uAttributes = 0;
        uIndex = 0;
        uKind = 0;
        uGroup = 0;
    }

    Vec3_int_ vPosition;
    uint16_t uRadius;
    uint16_t uKind;
    uint16_t uIndex;
    uint16_t uAttributes;
    unsigned int uGroup;

    inline bool IsMonsterSpawn() const { return uKind == 3; }
    inline bool IsTreasureSpawn() const { return uKind != 3; }
};
#pragma pack(pop)

/*   90 */
#pragma pack(push, 1)
struct BLVHeader {
    char field_0[104];
    unsigned int uFaces_fdata_Size;
    unsigned int uSector_rdata_Size;
    unsigned int uSector_lrdata_Size;
    unsigned int uDoors_ddata_Size;
    char field_78[16];
};
#pragma pack(pop)

/*   96 */
#pragma pack(push, 1)
struct BLVSectorMM8 {
    int dword_000074;
};
#pragma pack(pop)

/*   97 */
#pragma pack(push, 1)
struct BLVLightMM6 {
    Vec3_short_ vPosition;
    int16_t uRadius;
    int16_t uAttributes;
    uint16_t uBrightness;
};
#pragma pack(pop)

/*   98 */
#pragma pack(push, 1)
struct BLVLightMM7 {  // 10h
    struct Vec3_short_ vPosition;
    int16_t uRadius;
    char uRed;
    char uGreen;
    char uBlue;
    char uType;
    int16_t uAtributes;  // & 0x08    doesn't light faces
    int16_t uBrightness;
};
#pragma pack(pop)

/*   99 */
#pragma pack(push, 1)
struct BLVLightMM8 {
    int uID;
};
#pragma pack(pop)

/*  100 */
#pragma pack(push, 1)
struct BLVDoor {  // 50h
    enum State : uint16_t {
        Closed = 0,
        Opening = 1,
        Open = 2,
        Closing = 3
    };

    unsigned int uAttributes;
    unsigned int uDoorID;
    unsigned int uTimeSinceTriggered;
    Vec3_int_ vDirection;
    int uMoveLength;
    int uOpenSpeed;
    int uCloseSpeed;
    uint16_t *pVertexIDs;
    uint16_t *pFaceIDs;
    uint16_t *pSectorIDs;
    int16_t *pDeltaUs;
    int16_t *pDeltaVs;
    uint16_t *pXOffsets;
    uint16_t *pYOffsets;
    uint16_t *pZOffsets;
    uint16_t uNumVertices;
    uint16_t uNumFaces;
    int16_t field_48;
    uint16_t uNumOffsets;
    State uState;
    int16_t field_4E;
};
#pragma pack(pop)

/*  101 */
#pragma pack(push, 1)
struct BLVMapOutline {  // 0C
    uint16_t uVertex1ID;
    uint16_t uVertex2ID;
    uint16_t uFace1ID;
    uint16_t uFace2ID;
    int16_t sZ;
    uint16_t uFlags;
};
#pragma pack(pop)

/*   93 */
#pragma pack(push, 1)
struct BLVFace {  // 60h
    //----- (0046ED02) --------------------------------------------------------
    inline BLVFace() {
        this->uNumVertices = 0;
        this->uAttributes = 0;
        this->uFaceExtraID = 0;
        this->pVertexIDs = nullptr;
        this->pZInterceptDisplacements = nullptr;
        this->pYInterceptDisplacements = nullptr;
        this->pXInterceptDisplacements = nullptr;
    }

    void _get_normals(Vec3_int_ *a2, Vec3_int_ *a3);
    void FromODM(struct ODMFace *face);

    void SetTexture(const String &filename);
    Texture *GetTexture();

    bool Deserialize(struct BLVFace_MM7 *);

    inline bool Invisible() const {
        return (uAttributes & FACE_INVISIBLE) != 0;
    }
    inline bool Visible() const { return !Invisible(); }
    inline bool Portal() const { return (uAttributes & FACE_PORTAL) != 0; }
    inline bool Fluid() const { return (uAttributes & FACE_FLUID) != 0; }
    inline bool Indoor_sky() const {
        return (uAttributes & FACE_INDOOR_SKY) != 0;
    }
    inline bool Clickable() const {
        return (uAttributes & FACE_CLICKABLE) != 0;
    }
    inline bool Pressure_Plate() const {
        return (uAttributes & FACE_PRESSURE_PLATE) != 0;
    }
    inline bool Ethereal() const { return (uAttributes & FACE_ETHEREAL) != 0; }

    inline bool IsTextureFrameTable() const {
        return this->uAttributes & FACE_TEXTURE_FRAME;
    }
    inline void ToggleIsTextureFrameTable() {
        this->uAttributes = this->uAttributes & FACE_TEXTURE_FRAME
                                ? this->uAttributes & ~FACE_TEXTURE_FRAME
                                : this->uAttributes | FACE_TEXTURE_FRAME;
    }

    struct Plane_float_ pFacePlane;
    struct Plane_int_ pFacePlane_old;
    int zCalc1;
    int zCalc2;
    int zCalc3;
    unsigned int uAttributes;
    uint16_t *pVertexIDs;
    int16_t *pXInterceptDisplacements;
    int16_t *pYInterceptDisplacements;
    int16_t *pZInterceptDisplacements;
    int16_t *pVertexUIDs;
    int16_t *pVertexVIDs;
    uint16_t uFaceExtraID;
    void *resource;  // unsigned __int16  uBitmapID;
    uint16_t uSectorID;
    int16_t uBackSectorID;
    struct BBox_short_ pBounding;
    PolygonType uPolygonType;
    uint8_t uNumVertices;
    char field_5E;
    char field_5F;
};
#pragma pack(pop)

/*   94 */
#pragma pack(push, 1)
struct BLVFaceExtra {  // 24h
    bool HasEventint();

    int16_t field_0;
    int16_t field_2;
    int16_t field_4;
    int16_t field_6;
    int16_t field_8;
    int16_t field_A;
    int16_t face_id;
    uint16_t uAdditionalBitmapID;
    int16_t field_10;
    int16_t field_12;
    int16_t sTextureDeltaU;
    int16_t sTextureDeltaV;
    int16_t sCogNumber;
    uint16_t uEventID;
    int16_t field_1C;
    int16_t field_1E;
    int16_t field_20;
    int16_t field_22;
};
#pragma pack(pop)

/*   95 */
#pragma pack(push, 1)
struct BLVSector {  // 0x74
    int32_t field_0;
    uint16_t uNumFloors;
    int16_t field_6;
    uint16_t *pFloors;
    uint16_t uNumWalls;
    int16_t field_E;
    uint16_t *pWalls;
    uint16_t uNumCeilings;
    int16_t field_16;
    uint16_t *pCeilings;
    uint16_t uNumFluids;
    int16_t field_1E;
    uint16_t *pFluids;
    int16_t uNumPortals;
    int16_t field_26;
    uint16_t *pPortals;
    uint16_t uNumFaces;
    uint16_t uNumNonBSPFaces;
    uint16_t *pFaceIDs;
    uint16_t uNumCylinderFaces;
    int16_t field_36;
    int32_t pCylinderFaces;
    uint16_t uNumCogs;
    int16_t field_3E;
    uint16_t *pCogs;
    uint16_t uNumDecorations;
    int16_t field_46;
    uint16_t *pDecorationIDs;
    uint16_t uNumMarkers;
    int16_t field_4E;
    uint16_t *pMarkers;
    uint16_t uNumLights;
    int16_t field_56;
    uint16_t *pLights;
    int16_t uWaterLevel;
    int16_t uMistLevel;
    int16_t uLightDistanceMultiplier;
    int16_t uMinAmbientLightLevel;
    int16_t uFirstBSPNode;
    int16_t exit_tag;
    BBox_short_ pBounding;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct BLVMapOutlines {
    int uNumOutlines;
    BLVMapOutline pOutlines[7000];
};
#pragma pack(pop)

/*   89 */
#pragma pack(push, 1)
struct IndoorLocation {
    //----- (00462592) --------------------------------------------------------
    inline IndoorLocation() {
        this->log = EngineIoc::ResolveLogger();
        this->decal_builder = EngineIoc::ResolveDecalBuilder();
        this->spell_fx_renderer = EngineIoc::ResolveSpellFxRenderer();
        this->lightmap_builder = EngineIoc::ResolveLightmapBuilder();
        this->particle_engine = EngineIoc::ResolveParticleEngine();

        bLoaded = 0;
        ptr_0002B8_sector_lrdata = 0;
        ptr_0002B4_doors_ddata = 0;
        ptr_0002B0_sector_rdata = 0;
        pLFaces = 0;
        pVertices = 0;
        pFaces = 0;
        pFaceExtras = 0;
        pSectors = 0;
        pLights = 0;
        pDoors = 0;
        pNodes = 0;
        pMapOutlines = 0;
        uNumSpawnPoints = 0;
        pSpawnPoints = 0;
        uNumSectors = 0;
    }

    int GetSector(int sX, int sY, int sZ);
    void Release();
    bool Alloc();
    bool Load(const String &filename, int num_days_played,
              int respawn_interval_days, char *pDest);
    void Draw();
    void ToggleLight(signed int uLightID, unsigned int bToggle);

    static unsigned int GetLocationIndex(const char *Str1);
    void ExecDraw(bool bD3D);
    // static void ExecDraw_sw(unsigned int uFaceID);
    void ExecDraw_d3d(unsigned int uFaceID,
                             struct IndoorCameraD3D_Vec4 *pVertices,
                             unsigned int uNumVertices,
                             struct RenderVertexSoft *pPortalBounding);
    void PrepareActorRenderList_BLV();
    void PrepareDecorationsRenderList_BLV(unsigned int uDecorationID, unsigned int uSectorID);
    void PrepareItemsRenderList_BLV();

    String filename;
    char field_20[48];
    unsigned int bLoaded;
    char field_54[404];
    struct BLVHeader blv;
    unsigned int uNumVertices;
    struct Vec3_short_ *pVertices;
    unsigned int uNumFaces;
    struct BLVFace *pFaces;
    unsigned int uNumFaceExtras;
    struct BLVFaceExtra *pFaceExtras;
    int uNumSectors;
    struct BLVSector *pSectors;
    int uNumLights;
    struct BLVLightMM7 *pLights;
    int uNumDoors;
    struct BLVDoor *pDoors;
    unsigned int uNumNodes;
    struct BSPNode *pNodes;
    BLVMapOutlines *pMapOutlines;
    uint16_t *pLFaces;
    uint16_t *ptr_0002B0_sector_rdata;
    uint16_t *ptr_0002B4_doors_ddata;
    uint16_t *ptr_0002B8_sector_lrdata;
    unsigned int uNumSpawnPoints;
    struct SpawnPointMM7 *pSpawnPoints;
    struct DDM_DLV_Header dlv;
    LocationTime_stru1 stru1;
    char _visible_outlines[875];
    char padding;

    Log *log = nullptr;
    DecalBuilder *decal_builder = nullptr;
    SpellFxRenderer *spell_fx_renderer = nullptr;
    LightmapBuilder *lightmap_builder = nullptr;
    ParticleEngine *particle_engine = nullptr;
};
#pragma pack(pop)

extern IndoorLocation *pIndoor;

/*  162 */
#pragma pack(push, 1)
struct BLVRenderParams {
    inline BLVRenderParams() {
        uViewportX = 0;
        uViewportY = 0;
        uViewportZ = 0;
        uViewportW = 0;
    }

    void Reset();

    int field_0_timer_;
    int _unused_uFlags;  // & INDOOR_CAMERA_DRAW_D3D_OUTLINES:  render d3d
                         // outlines
    Vec3_int_ _unused_vPartyPos;
    int _unused_sPartyRotY;
    int _unused_sPartyRotX;
    int uPartySectorID;
    int _unused_sCosineY;     // matches ODMRenderParams::int sines and cosines
    int _unused_sSineY;       // computed in 0048600E
    int _unused_sCosineNegX;  // merged into IndoorCameraD3D
    int _unused_sSineNegX;    // --//--
    float _unused_fCosineY;   // matches old IndoorCamera::fRotationCosineY (new
                              // IndoorCameraD3D::fRotationCosineY)
    float _unused_fSineY;     // matches old IndoorCamera::fRotationSineY   (new
                              // IndoorCameraD3D::fRotationSineY)
    float _unused_fCosineNegX;  // the same
    float _unused_fSineNegX;    // the same
    int bsp_fov_rad;            // fixpoint FOV in radians for BSP calculation
    int bsp_fov_rad_inv;
    unsigned int uTargetWidth;
    unsigned int uTargetHeight;
    unsigned int uViewportX;
    unsigned int uViewportY;
    unsigned int uViewportZ;
    unsigned int uViewportW;
    int fov;
    int *pTargetZBuffer;
    int uViewportHeight;
    int uViewportWidth;
    int uViewportCenterX;
    int uViewportCenterY;
    struct BspRenderer_PortalViewportData *field_7C;
    unsigned int uNumFacesRenderedThisFrame;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
};
#pragma pack(pop)
extern BLVRenderParams *pBLVRenderParams;

int GetPortalScreenCoord(unsigned int uFaceID);
bool PortalFrustrum(int pNumVertices, struct BspRenderer_PortalViewportData *a2,
                    struct BspRenderer_PortalViewportData *near_portal,
                    int uFaceID);
void PrepareBspRenderList_BLV();
void AddBspNodeToRenderList(unsigned int node_id);
void sub_4406BC(unsigned int node_id, unsigned int uFirstNode);  // idb
char DoInteractionWithTopmostZObject(int a1, int a2);
int sub_4AAEA6_transform(struct RenderVertexSoft *a1);
unsigned int FaceFlowTextureOffset(unsigned int uFaceID);  // idb
void BLV_UpdateUserInputAndOther();
int BLV_GetFloorLevel(int x, int y, int z, unsigned int uSectorID,
                      unsigned int *pFaceID);
void BLV_UpdateDoors();
void UpdateActors_BLV();
void BLV_ProcessPartyActions();
void Door_switch_animation(unsigned int uDoorID, int a2);  // idb: sub_449A49
int sub_4088E9(int a1, int a2, int a3, int a4, int a5, int a6);
void PrepareDrawLists_BLV();
void PrepareToLoadBLV(unsigned int bLoading);
int GetAlertStatus();
int _45063B_spawn_some_monster(struct MapInfo *a1, int a2);
int sub_450521_ProllyDropItemAt(int ecx0, signed int a2, int a3, int a4, int a5,
                                uint16_t a6);

bool sub_4075DB(int a1, int a2, int a3, struct BLVFace *face);
bool sub_4077F1(int a1, int a2, int a3, struct ODMFace *face,
                struct BSPVertexBuffer *a5);

#pragma once

/*  165 */
#pragma pack(push, 1)
struct BspRenderer_PortalViewportData {
    void GetViewportData(int16_t x, int y, int16_t z, int w);

    int _viewport_space_y;
    int _viewport_space_w;
    int _viewport_space_x;
    int _viewport_space_z;
    int _viewport_x_minID;
    int _viewport_z_maxID;
    int16_t viewport_left_side[480];
    int16_t viewport_right_side[480];
};
#pragma pack(pop)
extern BspRenderer_PortalViewportData stru_F8A590;

/*  164 */
#pragma pack(push, 1)
struct BspRenderer_stru0 {
    //----- (0043F2BF) --------------------------------------------------------
    inline BspRenderer_stru0() {
        // _eh_vector_constructor_iterator_(std__vector_0007AC, 24, 4,
        //    (void ( *)(void *))IndoorCameraD3D_Vec4::IndoorCameraD3D_Vec4,
        //    (void ( *)(void *))IndoorCameraD3D_Vec4::dtor);
        // for (int i = 0; i < 4; ++i)
        //  pVertices[i].flt_2C = 0.0f;
    }

    //----- (0043F2A9) --------------------------------------------------------
    ~BspRenderer_stru0() {
        // _eh_vector_destructor_iterator_(this->std__vector_0007AC, 24, 4,
        // IndoorCameraD3D_Vec4::dtor);
    }

    uint16_t uSectorID;
    uint16_t uViewportX;
    uint16_t uViewportY;
    uint16_t uViewportZ;
    uint16_t uViewportW;
    int16_t field_A;
    BspRenderer_PortalViewportData PortalScreenData;
    uint16_t uFaceID;
    int16_t field_7A6;
    unsigned int viewing_portal_id;  // portal through which we're seeing this node
    IndoorCameraD3D_Vec4 std__vector_0007AC[4]; // frustum planes
    RenderVertexSoft pPortalBounding[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct BspFace {
    uint16_t uFaceID;
    uint16_t uNodeID;
};
#pragma pack(pop)

/*  163 */
#pragma pack(push, 1)
struct BspRenderer {  // stru170
    //----- (0043F282) --------------------------------------------------------
    inline BspRenderer() {
        // _eh_vector_constructor_iterator_(field_FA8, 2252, 150,
        //    (void ( *)(void *))stru170_stru0::stru170_stru0,
        //    (void ( *)(void *))stru170_stru0::dtor);
        num_faces = 0;
        num_nodes = 0;
        uNumVisibleNotEmptySectors = 0;
    }

    // void AddFaceToRenderList_sw(unsigned int node_id, unsigned int uFaceID);
    void AddFaceToRenderList_d3d(unsigned int node_id, unsigned int uFaceID);
    void MakeVisibleSectorList();
    // void DrawFaceOutlines();

    unsigned int num_faces;
    // __int16 pFaceIDs[2000];
    BspFace faces[1000];
    // char field_130[3700];
    unsigned int num_nodes;
    BspRenderer_stru0 nodes[150];
    unsigned int uNumVisibleNotEmptySectors;
    uint16_t pVisibleSectorIDs_toDrawDecorsActorsEtcFrom[6];
};
#pragma pack(pop)

extern struct BspRenderer *pBspRenderer;  // idb

void FindBillboardsLightLevels_BLV();

int collide_against_floor_approximate(int x, int y, int z,
                                      unsigned int *pSectorID,
                                      unsigned int *pFaceID);  // idb

bool sub_407A1C(int x, int z, int y, struct Vec3_int_ v);  // idb
