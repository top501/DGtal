/**
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
**/

#pragma once

/**
* @file Display3DFactory.h
* @author Martial Tola <http://liris.cnrs.fr/martial.tola/>
* @date mercredi 21 septembre 2011
*
* @brief
*
* Header file for module Display3DFactory
*
* This file is part of the DGtal library.
*/

#if defined(Display3DFactory_RECURSES)
#error Recursive header files inclusion detected in Display3DFactory.h
#else // defined(Display3DFactory_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Display3DFactory_RECURSES

#if !defined Display3DFactory_h
/** Prevents repeated inclusion of headers. */
#define Display3DFactory_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions

#include "DGtal/helpers/StdDefs.h"
#include "DGtal/base/Common.h"

#include "DGtal/io/DrawWithDisplay3DModifier.h"
#include "DGtal/geometry/curves/ArithmeticalDSS3d.h"
#include "DGtal/kernel/sets/DigitalSetBySTLSet.h"
#include "DGtal/kernel/sets/DigitalSetBySTLVector.h"
#include "DGtal/kernel/domains/HyperRectDomain.h"
#include "DGtal/topology/KhalimskySpaceND.h"
#include "DGtal/topology/Object.h"
#include "DGtal/kernel/PointVector.h"
#include "DGtal/geometry/curves/GridCurve.h"
#include "DGtal/shapes/Mesh.h"
#include "DGtal/geometry/tools/SphericalAccumulator.h"
#include "DGtal/io/colormaps/HueShadeColorMap.h"
#include "DGtal/io/colormaps/CColorMap.h"
#include "DGtal/images/ImageContainerBySTLVector.h"
#include "DGtal/images/ImageContainerBySTLMap.h"
#include "DGtal/images/ConstImageAdapter.h"
#include "DGtal/images/ImageAdapter.h"

//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{
/////////////////////////////////////////////////////////////////////////////
// struct Display3DFactory
/**
* Description of struct 'Display3DFactory' <p>
* \brief Factory for GPL Display3D:
*/
struct Display3DFactory
{

  // SphericalAccumulator
  /**
* Display an spherical accumulator in 3D. Bin values are mapped
* using a default HueShadeColorMap.
*
* @param display current display
* @param accumulator the accumulator to display
* @param shift translate vector for display purposes (default:
* zero vector)
* @param radius scale factor for the unit sphere radius (default:1)
* @tparam TVector a vector model
*/
  template <typename TVector, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const DGtal::SphericalAccumulator<TVector> & accumulator,
                    const typename DGtal::SphericalAccumulator<TVector>::RealVector &shift =
      typename DGtal::SphericalAccumulator<TVector>::RealVector(0,0,0),
                    const double radius=1.0);
  // SphericalAccumulator

  // Mesh
  template <typename TPoint, typename S, typename KS>
  static void drawAsFaces( Display3D<S, KS> & display, const DGtal::Mesh<TPoint> & );

  template <typename TPoint, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const DGtal::Mesh<TPoint> & );
  // Mesh



  // ArithmeticalDSS3d
  /**
* Default drawing style object.
* @return the dyn. alloc. default style for this object.
*/
  template <typename TIterator, typename TInteger, int connectivity>
  static DGtal::DrawableWithDisplay3D * defaultStyle( std::string, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & );

  template <typename TIterator, typename TInteger, int connectivity, typename S, typename KS>
  static void drawAsBalls( Display3D<S, KS> & display, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & );

  template <typename TIterator, typename TInteger, int connectivity, typename S, typename KS>
  static void drawAsBoundingBox( Display3D<S, KS> & display, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & );

  template <typename TIterator, typename TInteger, int connectivity, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & );
  // ArithmeticalDSS3d


  // DigitalSetBySTLSet
  /**
* Default drawing style object.
* @return the dyn. alloc. default style for this object.
*/
  template<typename Domain>
  static DGtal::DrawableWithDisplay3D * defaultStyle( std::string, const DGtal::DigitalSetBySTLSet<Domain> & );

  template<typename Domain, typename S, typename KS>
  static void drawAsPavingTransparent( Display3D<S, KS> & display, const DGtal::DigitalSetBySTLSet<Domain> & );

  template<typename Domain, typename S, typename KS>
  static void drawAsPaving( Display3D<S, KS> & display, const DGtal::DigitalSetBySTLSet<Domain> & );

  template<typename Domain, typename S, typename KS>
  static void drawAsGrid( Display3D<S, KS> & display, const DGtal::DigitalSetBySTLSet<Domain> & );

  template<typename Domain, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const DGtal::DigitalSetBySTLSet<Domain> & );
  // DigitalSetBySTLSet


  // DigitalSetBySTLVector
  /**
* Default drawing style object.
* @return the dyn. alloc. default style for this object.
*/
  template<typename Domain>
  static DGtal::DrawableWithDisplay3D * defaultStyle( std::string, const DGtal::DigitalSetBySTLVector<Domain> & );

  template<typename Domain, typename S, typename KS>
  static void drawAsPavingTransparent( Display3D<S, KS> & display, const DGtal::DigitalSetBySTLVector<Domain> & );

  template<typename Domain, typename S, typename KS>
  static void drawAsPaving( Display3D<S, KS> & display, const DGtal::DigitalSetBySTLVector<Domain> & );

  template<typename Domain, typename S, typename KS>
  static void drawAsGrid( Display3D<S, KS> & display, const DGtal::DigitalSetBySTLVector<Domain> & );

  template<typename Domain, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const DGtal::DigitalSetBySTLVector<Domain> & );
  // DigitalSetBySTLVector


  // HyperRectDomain
  /**
* Default drawing style object.
* @return the dyn. alloc. default style for this object.
*/
  template<typename TSpace>
  static DGtal::DrawableWithDisplay3D * defaultStyle( std::string, const DGtal::HyperRectDomain<TSpace> & );

  template<typename TSpace, typename S, typename KS>
  static void drawAsBoundingBox( Display3D<S, KS> & display, const DGtal::HyperRectDomain<TSpace> & );

  template<typename TSpace, typename S, typename KS>
  static void drawAsGrid( Display3D<S, KS> & display, const DGtal::HyperRectDomain<TSpace> & );

  template<typename TSpace, typename S, typename KS>
  static void drawAsPavingBalls( Display3D<S, KS> & display, const DGtal::HyperRectDomain<TSpace> & );

  template<typename TSpace, typename S, typename KS>
  static void drawAsPaving( Display3D<S, KS> & display, const DGtal::HyperRectDomain<TSpace> & );

  template<typename TSpace, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const DGtal::HyperRectDomain<TSpace> & );
  // HyperRectDomain


  // KhalimskyCell
  /**
* Default drawing style object.
* @return the dyn. alloc. default style for this object.
*/
  template < Dimension dim, typename TInteger >
  static DGtal::DrawableWithDisplay3D * defaultStyle( std::string, const DGtal::KhalimskyCell<dim, TInteger> & );

  template < Dimension dim, typename TInteger, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const DGtal::KhalimskyCell<dim, TInteger> & );
  // KhalimskyCell


  // Object
  template <typename TDigitalTopology, typename TDigitalSet>
  static DGtal::DrawableWithDisplay3D * defaultStyle( std::string, const DGtal::Object<TDigitalTopology, TDigitalSet> & );

  template <typename TDigitalTopology, typename TDigitalSet, typename S, typename KS>
  static void drawWithAdjacencies( Display3D<S, KS> & display, const DGtal::Object<TDigitalTopology, TDigitalSet> & );

  template <typename TDigitalTopology, typename TDigitalSet, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const DGtal::Object<TDigitalTopology, TDigitalSet> & );
  // Object


  // PointVector
  /**
* Default drawing style object.
* @return the dyn. alloc. default style for this object.
*/
  template<Dimension dim, typename TComponent>
  static DGtal::DrawableWithDisplay3D * defaultStyle( std::string, const DGtal::PointVector<dim,TComponent> & );

  template<Dimension dim, typename TComponent, typename S, typename KS>
  static void drawAsGrid( Display3D<S, KS> & display, const DGtal::PointVector<dim,TComponent> & );

  template<Dimension dim, typename TComponent, typename S, typename KS>
  static void drawAsPaving( Display3D<S, KS> & display, const DGtal::PointVector<dim,TComponent> & );

  template<Dimension dim, typename TComponent, typename S, typename KS>
  static void drawAsPavingWired( Display3D<S, KS> & display, const DGtal::PointVector<dim,TComponent> & );

  template<Dimension dim, typename TComponent, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const DGtal::PointVector<dim,TComponent> & );

  template<Dimension dim, typename TComponent, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const DGtal::PointVector<dim,TComponent> & , const DGtal::PointVector<dim,TComponent> & );
  // PointVector


  // SignedKhalimskyCell
  /**
* Default drawing style object.
* @return the dyn. alloc. default style for this object.
*/
  template< Dimension dim, typename TInteger >
  static DGtal::DrawableWithDisplay3D * defaultStyle( std::string, const DGtal::SignedKhalimskyCell<dim, TInteger> & );

  template< Dimension dim, typename TInteger, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const DGtal::SignedKhalimskyCell<dim, TInteger> & );
  // SignedKhalimskyCell

  // GridCurve
  template< typename TKSpace, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const DGtal::GridCurve<TKSpace> & );
  // GridCurve

  // SCellsRange
  template < typename TIterator, typename TSCell , typename S, typename KS>
  static void draw( DGtal::Display3D<S, KS> & display,
                    const DGtal::ConstRangeAdapter<TIterator, DGtal::DefaultFunctor, TSCell> & );
  // SCellsRange

  // PointsRange
  template <typename TIterator, typename TKSpace, typename S, typename KS>
  static void draw( Display3D<S, KS> & display,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToPoint<TKSpace>, typename TKSpace::Point> & );
  // PointsRange

  // MidPointsRange
  template <typename TIterator, typename TKSpace, typename S, typename KS>
  static void draw( Display3D<S, KS> & display,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToMidPoint<TKSpace>,
                    typename TKSpace::Space::RealPoint> & );
  // MidPointsRange

  // ArrowsRange
  template <typename TIterator, typename TKSpace, typename S, typename KS>
  static void draw( Display3D<S, KS> & display,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToArrow<TKSpace>,
                    std::pair<typename TKSpace::Point, typename TKSpace::Vector > > & );
  // ArrowsRange

  // InnerPointsRange
  template <typename TIterator, typename TKSpace, typename S, typename KS>
  static void draw( Display3D<S, KS> & display,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToInnerPoint<TKSpace>, typename TKSpace::Point> & );
  // InnerPointsRange

  // OuterPointsRange
  template <typename TIterator, typename TKSpace, typename S, typename KS>
  static void draw( Display3D<S, KS> & display,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToOuterPoint<TKSpace>, typename TKSpace::Point> & );
  // OuterPointsRange

  // IncidentPointsRange
  template <typename TIterator, typename TKSpace, typename S, typename KS>
  static void draw( Display3D<S, KS> & display,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToIncidentPoints<TKSpace>,
                    std::pair<typename TKSpace::Point, typename TKSpace::Point > > & );
  // IncidentPointsRange


  // ImageContainerBySTLVector (2D)
  template <typename TValue, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const ImageContainerBySTLVector<DGtal::Z2i::Domain, TValue> &anImage);
  // ImageContainerBySTLVector (2D)

  // ImageContainerBySTLMap (2D)
  template <typename TValue, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const ImageContainerBySTLMap<DGtal::Z2i::Domain, TValue> &anImage);
  // ImageContainerBySTLMap (2D)

  // ConstImageAdapter (2D)
  template <typename TImageContainer, typename TFunctorD, typename TNewValue, typename TFunctorValue, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const ConstImageAdapter<TImageContainer, DGtal::Z2i::Domain, TFunctorD,
                    TNewValue, TFunctorValue> &anImage);
  // ConstImageAdapter (2D)

  // ImageAdapter (2D)
  template <typename TImageContainer, typename TFunctorD, typename TNewValue, typename TFunctorValue, typename TFunctorValueVm1, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const ImageAdapter<TImageContainer, DGtal::Z2i::Domain, TFunctorD,
                    TNewValue, TFunctorValue, TFunctorValueVm1> &anImage);
  // ImageAdapter (2D)


  // ImageContainerBySTLVector (3D)
  template <typename TValue, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const ImageContainerBySTLVector<DGtal::Z3i::Domain, TValue> &anImage);
  // ImageContainerBySTLVector (3D)


  // ImageContainerBySTLMap (3D)
  template <typename TValue, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const ImageContainerBySTLMap<DGtal::Z3i::Domain, TValue> &anImage);
  // ImageContainerBySTLMap (3D)

  // ConstImageAdapter (3D)
  template <typename TImageContainer, typename TFunctorD, typename TNewValue, typename TFunctorValue, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const ConstImageAdapter<TImageContainer, DGtal::Z3i::Domain, TFunctorD,
                    TNewValue, TFunctorValue> &anImage);
  // ConstImageAdapter (3D)

  // ImageAdapter (3D)
  template <typename TImageContainer, typename TFunctorD, typename TNewValue, typename TFunctorValue, typename TFunctorValueVm1, typename S, typename KS>
  static void draw( Display3D<S, KS> & display, const ImageAdapter<TImageContainer, DGtal::Z3i::Domain, TFunctorD,
                    TNewValue, TFunctorValue, TFunctorValueVm1> &anImage);
  // ImageAdapter (3D)




  template < typename TImageType2D, typename TFunctor, typename S, typename KS>
  static void
  drawImage2D( Display3D<S, KS> & display, const TImageType2D &anImage, const TFunctor &aFunctor,
               typename Display3D<S, KS>::TextureMode aTextureMode= Display3D<S, KS>::GrayScaleMode);


  template < typename TImageType3D, typename TFunctor, typename S, typename KS>
  static void
  drawImage3D( Display3D<S, KS> & display, const TImageType3D &anImage3D, const TFunctor &aFunctor,
               typename Display3D<S, KS>::TextureMode aTextureMode= Display3D<S, KS>::GrayScaleMode);



  template < typename S, typename KS>
  static void
  draw( Display3D<S, KS> & display, const DGtal::SetMode3D & );

  template < typename S, typename KS>
  static void
  draw( Display3D<S, KS> & display, const DGtal::CustomStyle3D & );

  template < typename S, typename KS>
  static void
  draw( Display3D<S, KS> & display, const DGtal::CustomColors3D & );

  template < typename S, typename KS>
  static void
  draw( Display3D<S, KS> & display, const DGtal::ClippingPlane & );

  template<typename TImageType, typename TFunctor, typename S, typename KS>
  static void
  draw( Display3D<S, KS> & display, const DGtal::UpdateImageData<TImageType, TFunctor> & );

  template<typename TImageType, typename TFunctor, typename S, typename KS>
  static void
  draw( Display3D<S, KS> & display, const DGtal::AddTextureImage3DWithFunctor<TImageType, TFunctor, S, KS> & );

  template<typename TImageType, typename TFunctor, typename S, typename KS>
  static void
  draw( Display3D<S, KS> & display, const DGtal::AddTextureImage2DWithFunctor<TImageType, TFunctor, S, KS> & );

  template < typename S, typename KS>
  static void
  draw( Display3D<S, KS> & display, const DGtal::UpdateImagePosition< S, KS> & anUpdate);

  template < typename S, typename KS>
  static void
  draw( Display3D<S, KS> & display, const DGtal::UpdateLastImagePosition< S, KS> & anUpdate );

  template < typename S, typename KS>
  static void
  draw( Display3D<S, KS> &display, const DGtal::Update2DDomainPosition< S, KS> &anUpdate);

  template < typename S, typename KS>
  static void
  draw(Display3D<S, KS> &display, const DGtal::Translate2DDomain &anTranslation);

  template < typename S, typename KS>
  static void
  draw( Display3D<S, KS> & display, const DGtal::TransformedSurfelPrism & aTransformedSurfelPrism);


}; // end of struct Display3DFactory

} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions/methods
#include "DGtal/io/Display3DFactory.ih"


// //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined Display3DFactory_h

#undef Display3DFactory_RECURSES
#endif // else defined(Display3DFactory_RECURSES)
