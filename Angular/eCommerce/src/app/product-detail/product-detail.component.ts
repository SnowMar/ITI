import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { ProductService } from '../services/product.service';
import { Item } from '../types/item';
import { CommonModule } from '@angular/common';

@Component({
  selector: 'app-product-detail',
  standalone: true, // Add if using standalone components
  imports: [CommonModule], // Add CommonModule for common directives
  templateUrl: './product-detail.component.html',
  styleUrls: ['./product-detail.component.css']
})
export class ProductDetailComponent implements OnInit {
  product: Item | undefined;
  quantity: number = 1;

  constructor(
    private route: ActivatedRoute,
    private productService: ProductService
  ) {}

  ngOnInit() {
    const id = Number(this.route.snapshot.paramMap.get('id'));
    this.productService.getProductById(id).subscribe(
      (product: Item | undefined) => this.product = product
    );
  }

  setMainImage(image: string): void {
    if (this.product) {
      this.product.images[0] = image;
    }
  }

  updateQuantity(value: string): void {
    this.quantity = parseInt(value, 10) || 0; // Default to 0 if input is invalid
  }

  increaseQuantity(): void {
    this.quantity++;
  }

  decreaseQuantity(): void {
    if (this.quantity > 0) {
      this.quantity--;
    }
  }

  buyNow(): void {
    console.log('Redirecting to buy now page...');
  }

  addToCart(): void {
    console.log('Adding product to cart...');
  }
}