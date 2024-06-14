//
// mlx_int.h for minilibx
//
// ol@staff.42.fr
//
// include opengl needed before mlx_int.h
//

#ifndef __gltypes_h_
#define __gltypes_h_

#include <stdint.h>

typedef uint32_t GLbitfield;
typedef uint8_t  GLboolean;
typedef int8_t   GLbyte;
typedef float    GLclampf;
typedef uint32_t GLenum;
typedef float    GLfloat;
typedef int32_t  GLint;
typedef int16_t  GLshort;
typedef int32_t  GLsizei;
typedef uint8_t  GLubyte;
typedef uint32_t GLuint;
typedef uint16_t GLushort;
typedef void     GLvoid;

#if !defined(GL_VERSION_2_0)
typedef char     GLchar;
#endif
#if !defined(GL_ARB_shader_objects)
typedef char     GLcharARB;
typedef void    *GLhandleARB;
#endif
typedef double   GLdouble;
typedef double   GLclampd;
#if !defined(ARB_ES2_compatibility) && !defined(GL_VERSION_4_1)
typedef int32_t  GLfixed;
#endif
#if !defined(GL_ARB_half_float_vertex) && !defined(GL_VERSION_3_0)
typedef uint16_t GLhalf;
#endif
#if !defined(GL_ARB_half_float_pixel)
typedef uint16_t GLhalfARB;
#endif
#if !defined(GL_ARB_sync) && !defined(GL_VERSION_3_2)
typedef int64_t  GLint64;
typedef struct __GLsync *GLsync;
typedef uint64_t GLuint64;
#endif
#if !defined(GL_EXT_timer_query)
typedef int64_t  GLint64EXT;
typedef uint64_t GLuint64EXT;
#endif
#if !defined(GL_VERSION_1_5)
typedef intptr_t GLintptr;
typedef intptr_t GLsizeiptr;
#endif
#if !defined(GL_ARB_vertex_buffer_object)
typedef intptr_t GLintptrARB;
typedef intptr_t GLsizeiptrARB;
#endif

#endif


#define	MAX_EVENT	32
#define MAX_PIXEL_NB	200000
#define UNIQ_BPP	4

#define FONT_WIDTH	10
#define	FONT_HEIGHT	20


typedef int (*func_t)();

/* structs */

typedef struct	glsl_info_s
{
  GLuint	pixel_vshader;
  GLuint	pixel_fshader;
  GLuint	pixel_program;
  GLint		loc_pixel_position;
  GLint		loc_pixel_texture;
  GLint		loc_pixel_winhalfsize;

  GLuint	image_vshader;
  GLuint	image_fshader;
  GLuint	image_program;
  GLint		loc_image_position;
  GLint		loc_image_winhalfsize;
  GLint		loc_image_texture;
  GLint		loc_image_pos;
  GLint		loc_image_size;

  GLuint	font_vshader;
  GLuint	font_fshader;
  GLuint	font_program;
  GLint		loc_font_position;
  GLint		loc_font_winhalfsize;
  GLint		loc_font_texture;
  GLint		loc_font_color;
  GLint		loc_font_posinwin;
  GLint		loc_font_posinatlas;
  GLint		loc_font_atlassize;
} glsl_info_t;


typedef struct	mlx_img_list_s
{
  int			width;
  int			height;
  char			*buffer;
  GLfloat		vertexes[8];
  struct mlx_img_list_s	*next;
} mlx_img_list_t;


typedef struct	mlx_img_ctx_s
{
  GLuint		texture;
  GLuint		vbuffer;
  mlx_img_list_t	*img;
  struct mlx_img_ctx_s	*next;
} mlx_img_ctx_t;

typedef struct	mlx_win_list_s
{
  void			*winid;
  mlx_img_ctx_t		*img_list;
  int			nb_flush;
  int			pixmgt;
  struct mlx_win_list_s	*next;
} mlx_win_list_t;


typedef struct		mlx_ptr_s
{
  void			*appid;
  mlx_win_list_t	*win_list;
  mlx_img_list_t	*img_list;
  void			(*loop_hook)(void *);
  void			*loop_hook_data;
  void			*loop_timer;
  mlx_img_list_t	*font;
  int			main_loop_active;
} mlx_ptr_t;

// proto

int	mlx_shaders(glsl_info_t *glsl);
char    **mlx_int_str_to_wordtab(char *str);
int     mlx_int_str_str(char *str,char *find,int len);
int     mlx_int_str_str_cote(char *str,char *find,int len);
int	mlx_destroy_image(mlx_ptr_t *mlx_ptr, mlx_img_list_t *img_ptr);
void	*mlx_new_image();
void    *mlx_xpm_to_image(mlx_ptr_t *xvar,char **xpm_data,int *width,int *height);
int	mlx_do_sync(mlx_ptr_t *mlx_ptr);
