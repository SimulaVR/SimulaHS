/* Generated by wayland-scanner 1.12.0 */

#ifndef MOTORCAR_SERVER_PROTOCOL_H
#define MOTORCAR_SERVER_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_client;
struct wl_resource;

/**
 * @page page_motorcar The motorcar protocol
 * @section page_ifaces_motorcar Interfaces
 * - @subpage page_iface_motorcar_shell - a 3D compositor shell
 * - @subpage page_iface_motorcar_surface - a 3D, view dependent, depth composited meta-data surface
 * - @subpage page_iface_motorcar_viewpoint - represents a single viewpoint in the compositor, essentially a view and projection matrix
 * - @subpage page_iface_motorcar_six_dof_pointer - six degree of freedom pointer input device
 */
struct motorcar_shell;
struct motorcar_six_dof_pointer;
struct motorcar_surface;
struct motorcar_viewpoint;
struct wl_surface;

/**
 * @page page_iface_motorcar_shell motorcar_shell
 * @section page_iface_motorcar_shell_desc Description
 *
 * An interface to allow a copositor to composite 3D data from multiple clients
 * in a manner that makes it appear to be in the same 3D space. Combined with
 * embedding tradtional wayland surfaces on quads in the same space it provides the 
 * framework needed to achieve a seamless mixture of 2D and 3D user interfaces while 
 * still giving clients full flexibility in how their content is drawn to 2D
 *
 * It allows clients to associate a motorcar_surface with a basic surface, which
 * both tells the compositor to perform 3D compositing on the client surface, and also
 * provides a mechanism for the compositor to give the client the information it needs to draw
 * its content to 2D correctly.
 * @section page_iface_motorcar_shell_api API
 * See @ref iface_motorcar_shell.
 */
/**
 * @defgroup iface_motorcar_shell The motorcar_shell interface
 *
 * An interface to allow a copositor to composite 3D data from multiple clients
 * in a manner that makes it appear to be in the same 3D space. Combined with
 * embedding tradtional wayland surfaces on quads in the same space it provides the 
 * framework needed to achieve a seamless mixture of 2D and 3D user interfaces while 
 * still giving clients full flexibility in how their content is drawn to 2D
 *
 * It allows clients to associate a motorcar_surface with a basic surface, which
 * both tells the compositor to perform 3D compositing on the client surface, and also
 * provides a mechanism for the compositor to give the client the information it needs to draw
 * its content to 2D correctly.
 */
extern const struct wl_interface motorcar_shell_interface;
/**
 * @page page_iface_motorcar_surface motorcar_surface
 * @section page_iface_motorcar_surface_desc Description
 *
 * An interface that may be implemented by a wl_surface, for
 * implementations that provide motorcar style depth composited 3D surfaces
 *
 * A motorcar_surface can be created from an exisitng surface, and provides the client
 * with the information needed to draw its content in a way that can be depth composited by
 * a motorcar compliant compositor.
 *
 * A motorcar surface is handled in the compositor as a 3D analog of a traditional window. Rather than the window being a 2 dimensional region of a 2 dimensional interface space, the window represents a 3 dimensional region of a 3 dimensional interface space, essentially a 3D box in which the client can draw 3D geometry
 *
 * The 3D window has its own 3D space whose origin is at the center of the window. The window's position refers to the location of this origin in the world space, and its rotation is around this point. The window also has a 3D size, which is defined in its local space. Each component of the size indicates one dimension of the window bounds, so the window extends for one half this distance on each side of the origin in its local space.
 * @section page_iface_motorcar_surface_api API
 * See @ref iface_motorcar_surface.
 */
/**
 * @defgroup iface_motorcar_surface The motorcar_surface interface
 *
 * An interface that may be implemented by a wl_surface, for
 * implementations that provide motorcar style depth composited 3D surfaces
 *
 * A motorcar_surface can be created from an exisitng surface, and provides the client
 * with the information needed to draw its content in a way that can be depth composited by
 * a motorcar compliant compositor.
 *
 * A motorcar surface is handled in the compositor as a 3D analog of a traditional window. Rather than the window being a 2 dimensional region of a 2 dimensional interface space, the window represents a 3 dimensional region of a 3 dimensional interface space, essentially a 3D box in which the client can draw 3D geometry
 *
 * The 3D window has its own 3D space whose origin is at the center of the window. The window's position refers to the location of this origin in the world space, and its rotation is around this point. The window also has a 3D size, which is defined in its local space. Each component of the size indicates one dimension of the window bounds, so the window extends for one half this distance on each side of the origin in its local space.
 */
extern const struct wl_interface motorcar_surface_interface;
/**
 * @page page_iface_motorcar_viewpoint motorcar_viewpoint
 * @section page_iface_motorcar_viewpoint_desc Description
 *
 * This interface represents a viewpoint (essentially a virtual camera) in the compositor's 3D compositing space, 
 * and the events it contains are designed to keep the compositor and client viewpoints synced so that the viewpoints 
 * in the client and compositor space stay consistent;
 *
 * @section page_iface_motorcar_viewpoint_api API
 * See @ref iface_motorcar_viewpoint.
 */
/**
 * @defgroup iface_motorcar_viewpoint The motorcar_viewpoint interface
 *
 * This interface represents a viewpoint (essentially a virtual camera) in the compositor's 3D compositing space, 
 * and the events it contains are designed to keep the compositor and client viewpoints synced so that the viewpoints 
 * in the client and compositor space stay consistent;
 *
 */
extern const struct wl_interface motorcar_viewpoint_interface;
/**
 * @page page_iface_motorcar_six_dof_pointer motorcar_six_dof_pointer
 * @section page_iface_motorcar_six_dof_pointer_desc Description
 *
 * This interface represents a six degree of freedom pointing device which behaves much like a traditional pointing device except that 
 * rather then event being associated with a 2D position they are associated with a 3D position and orientation, 
 * represented as a 3-vector position and column major 3x3 rotation matrix as packed 32 bit float arrays (all values in meters).
 * Most of the events are the same as the traditional wayaland pointer events other than this. 
 *
 * The motorcar_six_dof_pointer interface generates motion, enter and leave
 * events for the surfaces that the six_dof pointer is located over,
 * and button and axis events for button presses, button releases
 * and scrolling.
 * @section page_iface_motorcar_six_dof_pointer_api API
 * See @ref iface_motorcar_six_dof_pointer.
 */
/**
 * @defgroup iface_motorcar_six_dof_pointer The motorcar_six_dof_pointer interface
 *
 * This interface represents a six degree of freedom pointing device which behaves much like a traditional pointing device except that 
 * rather then event being associated with a 2D position they are associated with a 3D position and orientation, 
 * represented as a 3-vector position and column major 3x3 rotation matrix as packed 32 bit float arrays (all values in meters).
 * Most of the events are the same as the traditional wayaland pointer events other than this. 
 *
 * The motorcar_six_dof_pointer interface generates motion, enter and leave
 * events for the surfaces that the six_dof pointer is located over,
 * and button and axis events for button presses, button releases
 * and scrolling.
 */
extern const struct wl_interface motorcar_six_dof_pointer_interface;

/**
 * @ingroup iface_motorcar_shell
 * @struct motorcar_shell_interface
 */
struct motorcar_shell_interface {
	/**
	 * create a motorcar surface from a surface
	 *
	 * Create a motorcar surface for an existing surface.
	 *
	 * Only one motorcar surface can be associated with a given
	 * surface.
	 * @param id the id of the new motorcar surface to be created
	 * @param surface the wl_surface which the motorcar_surface is to be associated with
	 * @param clipping_mode the clipping mode to be used by the compositor for this  surface
	 * @param enable_depth_compositing boolean value indicating whether to use depth buffer compositing on this surface
	 */
	void (*get_motorcar_surface)(struct wl_client *client,
				     struct wl_resource *resource,
				     uint32_t id,
				     struct wl_resource *surface,
				     uint32_t clipping_mode,
				     uint32_t enable_depth_compositing);
};


/**
 * @ingroup iface_motorcar_shell
 */
#define MOTORCAR_SHELL_GET_MOTORCAR_SURFACE_SINCE_VERSION 1

#ifndef MOTORCAR_SURFACE_CLIPPING_MODE_ENUM
#define MOTORCAR_SURFACE_CLIPPING_MODE_ENUM
/**
 * @ingroup iface_motorcar_surface
 * clipping behavior used by the compositor for a surface
 *
 * The compositor clips the fragments composing the 3D window to lie within its 3D window bounds.
 * The behavior of this clipping mechanism depends on the type of 3D window being clipped. This
 * compositor supports two clippling modes, called cuboid and portal clippling
 *
 * Cuboid clipping treats the 3D window as a box shaped region of the space (defined by the motorcar_surface size_3d)
 * and clips any fragments which do not lie withing this box.
 *
 * Portal clipping treats the 3D window as a 2D opening which connects two disjoint 3D spaces, much like a 
 * physical window. This drops any fragments which lie outside the projection of the window opening 
 * (defined by the first two dimensions of the motorcar_surface size_3d) and any fragments which lie closer 
 * to the viewpoint than the window opening 
 */
enum motorcar_surface_clipping_mode {
	/**
	 * Use the cuboid clipping mode
	 */
	MOTORCAR_SURFACE_CLIPPING_MODE_CUBOID = 0,
	/**
	 * Use the portal clipping mode
	 */
	MOTORCAR_SURFACE_CLIPPING_MODE_PORTAL = 1,
};
#endif /* MOTORCAR_SURFACE_CLIPPING_MODE_ENUM */

/**
 * @ingroup iface_motorcar_surface
 * @struct motorcar_surface_interface
 */
struct motorcar_surface_interface {
	/**
	 * requests that the client resize the 3D window to the given scale
	 *
	 * Sets the new size of the 3D window. If this size is larger
	 * than the size most recently requested by the compositor the
	 * compositor is free to clip the window to a new size, provided
	 * that it immediatly requests the client resize to those
	 * dimensions.
	 *
	 * The size is represented here as a vector of three 32-bit floats,
	 * representing the size of the 3D window along each of the
	 * cardinal axes in the window's local space.
	 * @param dimensions the new size vector
	 */
	void (*set_size_3d)(struct wl_client *client,
			    struct wl_resource *resource,
			    struct wl_array *dimensions);
};

#define MOTORCAR_SURFACE_TRANSFORM_MATRIX 0
#define MOTORCAR_SURFACE_REQUEST_SIZE_3D 1

/**
 * @ingroup iface_motorcar_surface
 */
#define MOTORCAR_SURFACE_TRANSFORM_MATRIX_SINCE_VERSION 1
/**
 * @ingroup iface_motorcar_surface
 */
#define MOTORCAR_SURFACE_REQUEST_SIZE_3D_SINCE_VERSION 1

/**
 * @ingroup iface_motorcar_surface
 */
#define MOTORCAR_SURFACE_SET_SIZE_3D_SINCE_VERSION 1

/**
 * @ingroup iface_motorcar_surface
 * Sends an transform_matrix event to the client owning the resource.
 * @param resource_ The client's resource
 * @param transform the new transform matrix
 */
static inline void
motorcar_surface_send_transform_matrix(struct wl_resource *resource_, struct wl_array *transform)
{
	wl_resource_post_event(resource_, MOTORCAR_SURFACE_TRANSFORM_MATRIX, transform);
}

/**
 * @ingroup iface_motorcar_surface
 * Sends an request_size_3d event to the client owning the resource.
 * @param resource_ The client's resource
 * @param dimensions the requested size vector
 */
static inline void
motorcar_surface_send_request_size_3d(struct wl_resource *resource_, struct wl_array *dimensions)
{
	wl_resource_post_event(resource_, MOTORCAR_SURFACE_REQUEST_SIZE_3D, dimensions);
}

#define MOTORCAR_VIEWPOINT_VIEW_MATRIX 0
#define MOTORCAR_VIEWPOINT_PROJECTION_MATRIX 1
#define MOTORCAR_VIEWPOINT_VIEW_PORT 2

/**
 * @ingroup iface_motorcar_viewpoint
 */
#define MOTORCAR_VIEWPOINT_VIEW_MATRIX_SINCE_VERSION 1
/**
 * @ingroup iface_motorcar_viewpoint
 */
#define MOTORCAR_VIEWPOINT_PROJECTION_MATRIX_SINCE_VERSION 1
/**
 * @ingroup iface_motorcar_viewpoint
 */
#define MOTORCAR_VIEWPOINT_VIEW_PORT_SINCE_VERSION 1


/**
 * @ingroup iface_motorcar_viewpoint
 * Sends an view_matrix event to the client owning the resource.
 * @param resource_ The client's resource
 * @param view the view matrix for this frame
 */
static inline void
motorcar_viewpoint_send_view_matrix(struct wl_resource *resource_, struct wl_array *view)
{
	wl_resource_post_event(resource_, MOTORCAR_VIEWPOINT_VIEW_MATRIX, view);
}

/**
 * @ingroup iface_motorcar_viewpoint
 * Sends an projection_matrix event to the client owning the resource.
 * @param resource_ The client's resource
 * @param projection the new projection matrix for this viewpoint
 */
static inline void
motorcar_viewpoint_send_projection_matrix(struct wl_resource *resource_, struct wl_array *projection)
{
	wl_resource_post_event(resource_, MOTORCAR_VIEWPOINT_PROJECTION_MATRIX, projection);
}

/**
 * @ingroup iface_motorcar_viewpoint
 * Sends an view_port event to the client owning the resource.
 * @param resource_ The client's resource
 * @param color_x x position of the color viewport, in pixels
 * @param color_y y position of the color viewport, in pixels
 * @param color_width width of the color viewport, in pixels
 * @param color_height height of the color viewport, in pixels
 * @param depth_x x position of the depth viewport, in pixels
 * @param depth_y y position of the depth viewport, in pixels
 * @param depth_width width of the depth viewport, in pixels
 * @param depth_height height of the depth viewport, in pixels
 */
static inline void
motorcar_viewpoint_send_view_port(struct wl_resource *resource_, int32_t color_x, int32_t color_y, uint32_t color_width, uint32_t color_height, int32_t depth_x, int32_t depth_y, uint32_t depth_width, uint32_t depth_height)
{
	wl_resource_post_event(resource_, MOTORCAR_VIEWPOINT_VIEW_PORT, color_x, color_y, color_width, color_height, depth_x, depth_y, depth_width, depth_height);
}

/**
 * @ingroup iface_motorcar_six_dof_pointer
 * @struct motorcar_six_dof_pointer_interface
 */
struct motorcar_six_dof_pointer_interface {
	/**
	 * release the six_dof pointer object
	 *
	 * 
	 */
	void (*release)(struct wl_client *client,
			struct wl_resource *resource);
};

#define MOTORCAR_SIX_DOF_POINTER_ENTER 0
#define MOTORCAR_SIX_DOF_POINTER_LEAVE 1
#define MOTORCAR_SIX_DOF_POINTER_MOTION 2
#define MOTORCAR_SIX_DOF_POINTER_BUTTON 3

/**
 * @ingroup iface_motorcar_six_dof_pointer
 */
#define MOTORCAR_SIX_DOF_POINTER_ENTER_SINCE_VERSION 1
/**
 * @ingroup iface_motorcar_six_dof_pointer
 */
#define MOTORCAR_SIX_DOF_POINTER_LEAVE_SINCE_VERSION 1
/**
 * @ingroup iface_motorcar_six_dof_pointer
 */
#define MOTORCAR_SIX_DOF_POINTER_MOTION_SINCE_VERSION 1
/**
 * @ingroup iface_motorcar_six_dof_pointer
 */
#define MOTORCAR_SIX_DOF_POINTER_BUTTON_SINCE_VERSION 1

/**
 * @ingroup iface_motorcar_six_dof_pointer
 */
#define MOTORCAR_SIX_DOF_POINTER_RELEASE_SINCE_VERSION 1

/**
 * @ingroup iface_motorcar_six_dof_pointer
 * Sends an enter event to the client owning the resource.
 * @param resource_ The client's resource
 * @param position position of pointing device in meters at the time of this event, represented as a packed array of three 32 bit floats
 * @param orientation orientation of the pointing device in meters at the time of this event, represented as a packed column major 3x3 rotation matrix of 32 bit floats
 */
static inline void
motorcar_six_dof_pointer_send_enter(struct wl_resource *resource_, uint32_t serial, struct wl_resource *surface, struct wl_array *position, struct wl_array *orientation)
{
	wl_resource_post_event(resource_, MOTORCAR_SIX_DOF_POINTER_ENTER, serial, surface, position, orientation);
}

/**
 * @ingroup iface_motorcar_six_dof_pointer
 * Sends an leave event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
motorcar_six_dof_pointer_send_leave(struct wl_resource *resource_, uint32_t serial, struct wl_resource *surface)
{
	wl_resource_post_event(resource_, MOTORCAR_SIX_DOF_POINTER_LEAVE, serial, surface);
}

/**
 * @ingroup iface_motorcar_six_dof_pointer
 * Sends an motion event to the client owning the resource.
 * @param resource_ The client's resource
 * @param time timestamp with millisecond granularity
 * @param position position of pointing device in meters at the time of this event, represented as a packed array of three 32 bit floats
 * @param orientation orientation of the pointing device in meters at the time of this event, represented as a packed column major 3x3 rotation matrix of 32 bit floats
 */
static inline void
motorcar_six_dof_pointer_send_motion(struct wl_resource *resource_, uint32_t time, struct wl_array *position, struct wl_array *orientation)
{
	wl_resource_post_event(resource_, MOTORCAR_SIX_DOF_POINTER_MOTION, time, position, orientation);
}

/**
 * @ingroup iface_motorcar_six_dof_pointer
 * Sends an button event to the client owning the resource.
 * @param resource_ The client's resource
 * @param time timestamp with millisecond granularity
 */
static inline void
motorcar_six_dof_pointer_send_button(struct wl_resource *resource_, uint32_t serial, uint32_t time, uint32_t button, uint32_t state)
{
	wl_resource_post_event(resource_, MOTORCAR_SIX_DOF_POINTER_BUTTON, serial, time, button, state);
}

#ifdef  __cplusplus
}
#endif

#endif
