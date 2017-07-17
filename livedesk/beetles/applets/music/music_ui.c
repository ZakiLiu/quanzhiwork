
//libaiao

#include "beetles_app.h"
#include "music_ui.h"

static music_ui_t  music_ui_400_240 =
{
    //layer window
    {
        PIXEL_COLOR_ARGB8888,       //fmt
        { 400, 240 },               //fb size
        { 0, 0, 400, 240 },         //src rect
        { 0, 0, 400, 240 },         //scn rect
        { 0 },                      //reserved
    },

    //list window, ����ļ�
    {
        {0, 7, 188, 216},						//listbar area
        {0, 0, 188, 36},						//item rectangle
        {5, 9, 181, 22},						//focus icon(select border)
        {11, 12, 15, 15 },						//file icon
        {11 + 15 + 10, 0, 188 - 11 - 15 - 10 - 3 - 1, 36},		//text rectangle
    },

    //scroll bar ui
    {
        {189,	7,	7,	224},					//scroll bar background
        {191,	22,	3,	194},					//scroll
        6,										//head
        1,										//body
        6,										//tail
    },

    //head bar ui
    {
        {210, 40, 400 - 210, 150 - 40},					//headbar background
#if BEETLES_RTC_EXIST
        {198, 5, 26, 16},								//����ģʽ״̬ͼ��
        {226, 5, 50, 16},								//EQģʽ״̬ͼ��
        {226, 5, 26, 16},								//����ر�ʱ��ͼ��
        {278, 5, 26, 16},								//����ͼ��
        {304, 3, 18, 16},								//����text
        {326, 6, 31, 12},								//���ͼ��
        {359, 3, 40, 16},								//ʱ����ʾ����
#else
        {198, 5, 26, 16},								//����ģʽ״̬ͼ��
        {229, 5, 50, 16},								//EQģʽ״̬ͼ��
        {284, 5, 26, 16},								//����ر�ʱ��ͼ��
        {315, 5, 26, 16},								//����ͼ��
        {341, 4, 18, 16},								//����text
        {364, 6, 31, 12},								//���ͼ��
        {0, 0, 0, 16},									//ʱ����ʾ����
#endif
    },
    //palyer ui
    {
        {210, 40, 400 - 210, 120 - 40},					//���ư�ť��������()��Ƶ�׹���
        {230, 120, 150, 16},							//������ʾ�ַ�����
        {254, 68, 26, 16},								//����ģʽ��ť
        {288, 68, 26, 16},								//EQģʽ��ť
        {324, 68, 26, 16},								// ����ʱ����ư�ť

        {228, 100, 26, 16},							//��һ�װ�ť
        {261, 100, 26, 16},							//��һ�װ�ť
        {294, 100, 26, 16},							//������ͣ��ť
        {327, 100, 26, 16},							//���˰�ť
        {360, 100, 26, 16},							//�����ť

        {214, 154, 26, 20},							//����״̬ͼ��(��ͣ�򲥷�)

        {239 + 3, 160 - 21, 70, 20},	              		//��ǰ����ʱ��
        {239 + 146 - 70 - 3 + 28 , 160 - 21, 60, 20},			//��ʱ����ʾ����

        {239, 160, 5, 4},								//������head
        {239, 160, 146, 4},							//������body
        {239 + 5, 160, 5, 4},							//������point,��head֮����˼�5
        {239 + 146 - 5, 160, 5, 4},						//������tail

        {213,		183, 26, 16},						//�ݳ���ͼ��
        {213 + 26,	183, 70, 16},						//�ݳ�������
        {310,		183, 26, 16},						//�ļ���Сͼ��
        {310 + 26,	183, 70, 16},						//�ļ���С��ʾ

        {213,		213, 26, 16},						//ר������ͼ��
        {213 + 26,	213, 70, 16},						//ר������
        {310,		213, 26, 16},						//bitrateͼ��
        {310 + 26,	213, 70, 16},						//bitrate��С��ʾ
    },

    //volume bar ui
    {
        {0, 0, 0, 0},									//��������������ʾ����
        {0, 0, 0, 0},									//���speakerͼ����ʾ��������״̬
        {0, 0, 0, 0},									//�м�������ʾ������
        {0, 0, 0, 0},    								//�ұ�speakerͼ����ʾ
    },

    //spectrum
    {
        {210, 40, 400 - 210, 150 - 40}
    },
    //icon table
    {
        //ID															res	handle,    	res buffer
        //���������
        { ID_MUSIC_PALETTE_BMP,           			NULL,  				 NULL },    //
        { NULL,           	NULL,  				 NULL },    //
        { ID_MUSIC_FILE_UNFOCUSED_BMP,      		NULL,  				 NULL }, 	//
        { ID_MUSIC_FILE_UNFOCUSED_BMP,      		NULL,  				 NULL }, 	//�ļ�ͼ�꣬δ��ѡ��ʱ
        { ID_MUSIC_FILE_FOCUSED_BMP,      			NULL,  				 NULL }, 	//�ļ�ͼ�꣬��ѡ��ʱ
        { ID_MUSIC_LIST_ITEM_FOCUS_BMP,    			NULL,  				 NULL }, 	//ѡ���
        { ID_MUSIC_LONG_STR_SCROLL_BMP,				NULL,  			 	 NULL },     //���ļ�������������
        //header bar
        //play mode
        { ID_MUSIC_PLAY_ALL_BMP,    				NULL,  				 NULL }, 	//	����ȫ��,���ظ�
        { ID_MUSIC_PLAY_ONE_BMP,    				NULL,  				 NULL }, 	//����һ��
        { ID_MUSIC_PLAY_RANDOM_BMP,    				NULL,  				 NULL }, 	//�漴����
        { ID_MUSIC_REPEAT_ALL_BMP,    				NULL,  				 NULL }, 	//�ظ�����
        { ID_MUSIC_REPEAT_ONE_BMP,    				NULL,  				 NULL }, 	//�ظ�һ��

        //EQ mode
        { ID_MUSIC_EQ_NORMAL_BMP,    				NULL,  				 NULL }, 	//EQ normal
        { ID_MUSIC_EQ_CLASSIC_BMP,    				NULL,  				 NULL }, 	//EQ classic
        { ID_MUSIC_EQ_ROCK_BMP,    					NULL,  				 NULL }, 	//	EQ Rock
        { ID_MUSIC_EQ_JAZZ_BMP,    					NULL,  				 NULL }, 	//	EQ JAZZ
        { ID_MUSIC_EQ_POP_BMP,    					NULL,  				 NULL }, 	//	EQ POP

        //BL Time
        { ID_MUSIC_BL_ON_BMP,    					NULL,  				 NULL }, 	//	Backlight never off
        { ID_MUSIC_BL_10S_BMP,    					NULL,  				 NULL }, 	//last 10 second
        { ID_MUSIC_BL_30S_BMP,    					NULL,  				 NULL }, 	//
        { ID_MUSIC_BL_60S_BMP,    					NULL,  				 NULL }, 	//
        { ID_MUSIC_BL_90S_BMP,    					NULL,  				 NULL }, 	//

        //volume
        { ID_MUSIC_VOLUME_STATUS_BMP,    			NULL,  				 NULL }, 	//

        //bettery
        { ID_MUSIC_BETTERY0_BMP,    				NULL,  				 NULL }, 	//
        { ID_MUSIC_BETTERY1_BMP,    				NULL,  				 NULL }, 	//
        { ID_MUSIC_BETTERY2_BMP,    				NULL,  				 NULL }, 	//
        { ID_MUSIC_BETTERY3_BMP,    				NULL,  				 NULL }, 	//
        { ID_MUSIC_BETTERY4_BMP,    				NULL,  				 NULL }, 	//
        { ID_MUSIC_BETTERY5_BMP,    				NULL,  				 NULL }, 	//

        { ID_MUSIC_CHARGE_BETTERY0_BMP,    				NULL,  				 NULL }, 	//
        { ID_MUSIC_CHARGE_BETTERY1_BMP,    				NULL,  				 NULL }, 	//
        { ID_MUSIC_CHARGE_BETTERY2_BMP,    				NULL,  				 NULL }, 	//
        { ID_MUSIC_CHARGE_BETTERY3_BMP,    				NULL,  				 NULL }, 	//
        { ID_MUSIC_CHARGE_BETTERY4_BMP,    				NULL,  				 NULL }, 	//
        { ID_MUSIC_CHARGE_BETTERY5_BMP,    				NULL,  				 NULL }, 	//

        //������
        //play mode button
        { ID_MUSIC_PLAY_ALL_BMP,    				NULL,  				 NULL }, 		//����ȫ��, unfocused
        { ID_MUSIC_PLAY_ALL_BTN_FOCUSED_BMP,		NULL,  				 NULL }, 		//����ȫ��, focused
        { ID_MUSIC_PLAY_ALL_BTN_PRESSED_BMP,		NULL,  				 NULL }, 		//����ȫ��, pressed

        { ID_MUSIC_PLAY_ONE_BMP,    				NULL,  				 NULL }, 		//����һ��, unfocused
        { ID_MUSIC_PLAY_ONE_BTN_FOCUSED_BMP,		NULL,  				 NULL }, 		//����һ��, focused
        { ID_MUSIC_PLAY_ONE_BTN_PRESSED_BMP,		NULL,  				 NULL }, 		//����һ��, pressed

        { ID_MUSIC_PLAY_RANDOM_BMP,    				NULL,  				 NULL }, 		//�������, unfocused
        { ID_MUSIC_PLAY_RANDOM_BTN_FOCUSED_BMP,		NULL,  				 NULL }, 		//�������, focused
        { ID_MUSIC_PLAY_RANDOM_BTN_PRESSED_BMP,		NULL,  				 NULL }, 		//�������, pressed

        { ID_MUSIC_REPEAT_ALL_BMP,    				NULL,  				 NULL }, 		//�ظ�����ȫ��, unfocused
        { ID_MUSIC_REPEAT_ALL_BTN_FOCUSED_BMP,		NULL,  				 NULL }, 		//�ظ�����ȫ��, focused
        { ID_MUSIC_REPEAT_ALL_BTN_PRESSED_BMP,		NULL,  				 NULL }, 		//�ظ�����ȫ��, pressed

        { ID_MUSIC_REPEAT_ONE_BMP,    				NULL,  				 NULL }, 		//�ظ�����һ��, unfocused
        { ID_MUSIC_REPEAT_ONE_BTN_FOCUSED_BMP,		NULL,  				 NULL }, 		//�ظ�����һ��, focused
        { ID_MUSIC_REPEAT_ONE_BTN_PRESSED_BMP,		NULL,  				 NULL }, 		//�ظ�����һ��, pressed

        //EQ mode button
        { ID_MUSIC_EQ_MODE_BTN_UNFOCUSED_BMP,		NULL,  				 NULL }, 		//EQ mode button, unfocused
        { ID_MUSIC_EQ_MODE_BTN_FOCUSED_BMP,			NULL,  				 NULL }, 		//focused
        { ID_MUSIC_EQ_MODE_BTN_PRESSED_BMP,			NULL,  				 NULL }, 		//pressed

        //BL time button
        { ID_MUSIC_BL_TIME_BTN_UNFOCUSED_BMP,		NULL,  				 NULL }, 		//EQ mode button, unfocused
        { ID_MUSIC_BL_TIME_BTN_FOCUSED_BMP,			NULL,  				 NULL }, 		//focused
        { ID_MUSIC_BL_TIME_BTN_PRESSED_BMP,			NULL,  				 NULL }, 		//pressed

        //play previous button
        { ID_MUSIC_PLAY_PRE_BTN_UNFOCUSED_BMP,		NULL,  				 NULL }, 	//������һ��, unfocused
        { ID_MUSIC_PLAY_PRE_BTN_FOCUSED_BMP,		NULL,  				 NULL }, 	//focused
        { ID_MUSIC_PLAY_PRE_BTN_PRESSED_BMP,		NULL,  				 NULL }, 		//pressed
        //play next button
        { ID_MUSIC_PLAY_NEXT_BTN_UNFOCUSED_BMP,		NULL,  				 NULL }, 	//������һ��, unfocused
        { ID_MUSIC_PLAY_NEXT_BTN_FOCUSED_BMP,		NULL,  				 NULL }, 	//focused
        { ID_MUSIC_PLAY_NEXT_BTN_PRESSED_BMP,		NULL,  				 NULL }, 	//pressed
        //play pause button
        { ID_MUSIC_PLAY_PAUSE_BTN_UNFOCUSED_BMP,	NULL,  				 NULL }, 	//������ͣ, unfocused
        { ID_MUSIC_PLAY_PAUSE_BTN_FOCUSED_BMP,		NULL,  				 NULL }, 	//focused
        { ID_MUSIC_PLAY_PAUSE_BTN_PRESSED_BMP,		NULL,  				 NULL }, 	//pressed

        //play backward button
        { ID_MUSIC_PLAY_BACKWARD_BTN_UNFOCUSED_BMP,	NULL,  				 NULL }, 	//����, unfocused
        { ID_MUSIC_PLAY_BACKWARD_BTN_FOCUSED_BMP,	NULL,  				 NULL }, 	//focused
        { ID_MUSIC_PLAY_BACKWARD_BTN_PRESSED_BMP,	NULL,  				 NULL }, 	//pressed

        //play forward button
        { ID_MUSIC_PLAY_FORWARD_BTN_UNFOCUSED_BMP,	NULL,  				 NULL }, 	//���, unfocused
        { ID_MUSIC_PLAY_FORWARD_BTN_FOCUSED_BMP,	NULL,  				 NULL }, 	//focused
        { ID_MUSIC_PLAY_FORWARD_BTN_PRESSED_BMP,	NULL,  				 NULL }, 	//pressed

        //play status button,
        { ID_MUSIC_PLAYING_STATUS_BMP,				NULL,				NULL }, 								//���ڲ���״̬
        { ID_MUSIC_PAUSE_STATUS_BMP,					NULL,  				NULL }, 								//��ͣ״̬
        { ID_MUSIC_PREVIOUS_STATUS_BMP,				NULL,  		 		NULL }, 								//��һ��״̬
        { ID_MUSIC_NEXT_STATUS_BMP,					NULL,  				NULL }, 								//��һ��״̬

        //process bar
        { ID_MUSIC_PROCESS_BAR_HEAD_BMP,				NULL,  			 	NULL }, 								//process bar ͷ��
        { ID_MUSIC_PROCESS_BAR_BODY_BMP,				NULL,  				NULL }, 								//body
        { ID_MUSIC_PROCESS_BAR_TAIL_BMP,				NULL,  		 		NULL }, 								//β��
        { ID_MUSIC_PROCESS_BAR_POINT_BMP,			NULL,  				NULL }, 								//���ȵ�

        //������Ϣͼ��
        { ID_MUSIC_PERFORMER_NAME_BMP,				NULL,  			 	NULL }, 								//����ͼ��
        { ID_MUSIC_FILE_SIZE_BMP,					NULL,  				NULL }, 								//
        { ID_MUSIC_ALBUM_NAME_BMP,					NULL,  		 		NULL }, 								//
        { ID_MUSIC_BIT_RATE_BMP,						NULL,  				NULL }, 								//

        //Ƶ��ͼͼ��
        { ID_MUSIC_PARTICLE_BMP,						NULL,  			 	NULL },
        { ID_MUSIC_BOUY_BMP,							NULL,  			 	NULL },

        //�������������
        { ID_MUSIC_LIST_SCROLL_BG_BMP,				NULL,  			 	NULL },
        { ID_MUSIC_LIST_SCROLL_HEAD_BMP,				NULL,  			 	NULL },
        { ID_MUSIC_LIST_SCROLL_BODY_BMP,				NULL,  			 	NULL },
        { ID_MUSIC_LIST_SCROLL_TAIL_BMP,				NULL,  			 	NULL },


        { 0,                                    		NULL,  				NULL }      	//browser_icon_max
    },
};

//�������explorer AP��Ƶ�UI����
music_ui_t *music_get_ui_param(void)
{
    return &(music_ui_400_240);
}

//������������UI����
music_list_ui_t *music_get_list_ui_param(void)
{
    return &(music_ui_400_240.list_ctrl);
}

//��ö���HeadbarUI����
music_headbar_ui_t *music_get_headbar_ui_param(void)
{
    return 	&(music_ui_400_240.headbar);
}

//��ö���playerUI����
music_palyer_ui_t *music_get_player_ui_param(void)
{
    return 	&(music_ui_400_240.player);
}

//���volume barUI����
music_volume_bar_ui_t *music_get_volume_bar_ui_param(void)
{
    return 	&(music_ui_400_240.volume_bar);
}
/*
************************************************************************************************************************
*Function	:         void* explorer_get_listview_icon_res(__u32 index)
*
*Description	:
*
*Arguments  	:
*
*Return     	:
*
************************************************************************************************************************
*/
void *music_get_icon_res(__u32 index)
{
    music_icon_data_t *icon_table = NULL;


    icon_table = music_ui_400_240.icon_table;

    if(index > MUSIC_ICON_MAX)
    {
        return NULL;
    }
    //__msg("----icon_id: %d, res_id: %d\n", index, icon_table[index].res_id);
    if(icon_table == NULL)
    {
        return NULL;
    }
    else if(icon_table[index].res_id == 0)
    {
        return NULL;
    }
    else if(icon_table[index].res_handle == NULL)
    {
#if 1
        icon_table[index].res_handle = theme_open(icon_table[index].res_id);
        icon_table[index].res_buffer = theme_hdl2buf(icon_table[index].res_handle);
        return icon_table[index].res_buffer;
#else
        {
            int i = 0;
            __msg("------------open all of the picture at first\n");
            app_print_memory_usage("new memory for picture resource", NULL);
            app_print_memory_usage("new memory for picture resource", NULL);
            for(i = 0; i < MUSIC_ICON_MAX; i++)
            {
                if(icon_table[i].res_handle == NULL)
                {
                    icon_table[i].res_handle = theme_open(icon_table[i].res_id);
                    icon_table[i].res_buffer = theme_hdl2buf(icon_table[i].res_handle);
                }
            }
            app_print_memory_usage("new memory for picture resource finished", NULL);

            return icon_table[index].res_buffer;
        }
#endif

    }
    else
    {
        return icon_table[index].res_buffer;
    }
}

/*
************************************************************************************************************************
*Function	:         __s32 explorer_free_listview_icon_res(void)
*
*Description	:
*
*Arguments  	:
*
*Return     	:
*
************************************************************************************************************************
*/
__s32 music_free_icon_res(void)
{
    __s32 i = 0;
    music_icon_data_t *icon_table = NULL;
    icon_table = music_ui_400_240.icon_table;

    if(icon_table == NULL)
    {
        return EPDK_FAIL;
    }
    else
    {
        //app_print_memory_usage("release memory for picture resource", NULL);
        //app_print_memory_usage("release memory for picture resource", NULL);
        for(i = 0; i < MUSIC_ICON_MAX; i++)
        {
            if(icon_table[i].res_handle != NULL)
            {
                theme_close(icon_table[i].res_handle);
                icon_table[i].res_handle = NULL;
                icon_table[i].res_buffer = NULL;
            }
        }
        //app_print_memory_usage("release memory for picture resource finished", NULL);
        return EPDK_OK;
    }
}

//���Explorer ����layer size
__s32 music_get_screen_rect(RECT *screen_rect)
{
    music_ui_t *ui_param;
    ui_param = music_get_ui_param();

    screen_rect->x = ui_param->layer.scn_rect.x;
    screen_rect->y = ui_param->layer.scn_rect.y;
    screen_rect->width = ui_param->layer.scn_rect.width;
    screen_rect->height = ui_param->layer.scn_rect.height;
    return EPDK_OK;
}

//����listbarÿҳ������ʾ����Ŀ����
__u32 music_count_listbar_pagenum(void)
{
    __u32 pagenum = 0;

    music_ui_t *ui_param;
    ui_param = music_get_ui_param();
    pagenum = ui_param->list_ctrl.listbar_rect.height / ui_param->list_ctrl.item_rect.height;
    return pagenum;
}












